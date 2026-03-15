/* Kiểm tra chuỗi tạo được từ các chữ cái*/
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        int count[26] = {0};
        for (char c : magazine) {
            count[c - 'a']++;
        }
        for (char c : ransomNote) {
            count[c - 'a']--;
            if (count[c - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    Solution s;
    string ransomNote = "a", magazine = "b";
    bool result = s.canConstruct(ransomNote, magazine);
    cout << (result ? "true" : "false") << endl;
    
    ransomNote = "aa", magazine = "ab";
    result = s.canConstruct(ransomNote, magazine);
    cout << (result ? "true" : "false") << endl;
}