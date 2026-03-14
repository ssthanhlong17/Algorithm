/* kiểm tra robot quay về điểm xuất phát khi di chuyển theo các hướng */
#include <iostream>
#include <string>
class Solution 
{
public:
    bool judgeCircle(std::string moves) 
    {
        int x = 0, y = 0;
        for (char c : moves) {
            switch (c) {
                case 'U': y++; break;
                case 'D': y--; break;
                case 'L': x--; break;
                case 'R': x++; break;
            }
        }
        return x == 0 && y == 0;
    }
};

int main() 
{
    std::string moves = "UDLR";
    Solution s;
    bool result = s.judgeCircle(moves);
    std::cout << (result ? "true" : "false") << std::endl;
}