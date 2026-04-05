#include <string.h>
#include "cmd_line.h"

uint8_t cmd_line_parser(cmd_line_t* cmd_table, uint8_t* command)
{
    uint8_t cmd_tmp[MAX_CMD_SIZE];      // Mảng tạm chứa từ khóa
    const uint8_t* p_cmd = command;     // Con trỏ để duyệt chuỗi lệnh
    uint8_t i = 0;                      // Đếm độ dài từ khóa
    uint8_t idx = 0;                    // Đếm vị trí bảng lệnh

    // Kiểm tra điều kiện đầu vào
    if (command[0] == '\0' || command[0] == '\r' || command[0] == '\n') return CMD_EMPTY;
    if (cmd_table == NULL) return CMD_TBL_NOT_FOUND;

    // Tách từ khóa đầu tiên từ chuỗi lệnh
    while(*p_cmd)
    {
        if(*p_cmd == ' ' || *p_cmd == '\r' || *p_cmd == '\n') break;    // Nếu gặp khoảng trắng hoặc kết thúc dòng
        if(i >= MAX_CMD_SIZE - 1) return CMD_TOO_LONG;                  // Nếu từ khóa quá dài
        cmd_tmp[i++] = *p_cmd++;                                        // Sao chép ký tự vào mảng tạm      
    }
    cmd_tmp[i] = '\0';                                                  // Kết thúc chuỗi tạm

    // Tìm kiếm từ khóa trong bảng lệnh
    while(cmd_table[idx].cmd != NULL)
    {
        if (strcmp((const char*)cmd_tmp, (const char*)cmd_table[idx].cmd) == 0) // So sánh từ khóa với bảng lệnh
        {
            cmd_table[idx].func(command);
            return CMD_SUCCESS;                                                 // Nếu tìm thấy, gọi hàm xử lý và trả về kết quả
        }
        idx++;
    }

    return CMD_NOT_FOUND;    // Nếu không tìm thấy lệnh nào khớp
}
