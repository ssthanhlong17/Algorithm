#ifndef CMD_LINE_H
#define CMD_LINE_H

#include <stdint.h>

#define MAX_CMD_SIZE 12         // Kích thước tối đa của lệnh
#define CMD_SUCCESS 0           // Lệnh thực thi thành công
#define CMD_TBL_NOT_FOUND 1     // Bảng lệnh không tìm thấy
#define CMD_NOT_FOUND 2         // Không tìm thấy lệnh trong bảng lệnh
#define CMD_TOO_LONG 3          // Lệnh quá dài
#define CMD_EMPTY 4             // Lệnh trống

typedef int32_t (*pf_cmd_func)(const uint8_t* argv);

typedef struct                  // Hiểu đơn giản nó sẽ là 1 dòng lệnh hợp lệ
{
    const int8_t* cmd;          // Từ khóa lệnh
    pf_cmd_func func;           // Hàm xử lý khi nhận từ khóa
    const int8_t* info;         // Thêm thông tin cụ thể từ khóa làm gì  
} cmd_line_t;

// Hàm này sẽ nhận vào 1 bảng lệnh và 1 chuỗi lệnh, sau đó sẽ tìm kiếm trong bảng lệnh để xem có lệnh nào khớp với chuỗi lệnh hay không. Nếu có, nó sẽ gọi hàm xử lý tương ứng với lệnh đó và trả về kết quả. Nếu không tìm thấy lệnh nào khớp, nó sẽ trả về mã lỗi phù hợp.
uint8_t cmd_line_parser(cmd_line_t* cmd_table, uint8_t* command);

#endif