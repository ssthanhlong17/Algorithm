#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include "cmd_line.h"

int32_t cmd_led_on(const uint8_t* argv)
{
    printf("LED ON\n");
    return CMD_SUCCESS;
}

int32_t cmd_get_version(const uint8_t* argv)
{
    printf("Version 1.0.0\n");
    return CMD_SUCCESS;
}

cmd_line_t cmd_table[] = {
    {"led_on", cmd_led_on, "Turn on the LED"},
    {(const int8_t*)"get_version", cmd_get_version, (const int8_t*)"Get the software version"},
    {NULL, NULL, NULL} // Kết thúc bảng lệnh
};

// 4 tham số đầu vào test_name: Tên của test case, table: Bảng lệnh để kiểm tra, input_str: Chuỗi lệnh đầu vào, expected_result: Kết quả mong đợi từ hàm cmd_line_parser
void run_test(const char* test_name, cmd_line_t* table, const char* input_str,uint8_t expected_result)
{
    uint8_t input[50];
    strcpy((char*)input, input_str);                // Sao chép chuỗi lệnh đầu vào vào mảng input để truyền vào hàm cmd_line_parser
    printf("Running test: %s\n", test_name);
    uint8_t result = cmd_line_parser(table, input); // Gọi hàm cmd_line_parser với bảng lệnh và chuỗi lệnh đầu vào, sau đó so sánh kết quả trả về với kết quả mong đợi
    if (result == expected_result) {
        printf("Test passed\n");
    } else {
        printf("Test failed: expected %d, got %d\n", expected_result, result);
    }
}

int main() {
    printf("--- BAT DAU KIEM THU ---\n\n");

    // Test 1: Lệnh đúng
    run_test("Lenh dung", cmd_table, "led_on", CMD_SUCCESS);

    // Test 2: Lệnh không tồn tại
    run_test("Lenh khong ton tai", cmd_table, "sontungMTP", CMD_NOT_FOUND);

    // Test 3: Bảng lệnh NULL
    run_test("Bang lenh NULL", NULL, "led_on", CMD_TBL_NOT_FOUND);

    // Test 4: Lệnh quá dài
    run_test("Lenh qua dai", cmd_table, "day_la_mot_lenh_rat_dai", CMD_TOO_LONG);

    // Test 5: Lệnh kèm tham số
    run_test("Lenh kem tham so", cmd_table, "get_version -all", CMD_SUCCESS);

    // Test 6: Lệnh rỗng
    run_test("Lenh rong", cmd_table, "", CMD_EMPTY);

    return 0;
}

