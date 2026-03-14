/* Tìm ký tự khác biệt giữa hai chuỗi */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        vector<int> count(26,0);
        for(char c : s)
        {
            count[c - 'a']++;
        }
        for(char c : t)
        {
            count[c - 'a']--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(count[i] != 0) return 'a' + i;
        }
        return ' ';
    }
};
int main()
{
    Solution s;
    string s1 = "abcd";
    string t1 = "abcde";
    cout << s.findTheDifference(s1, t1) << endl; // e

    string s2 = "";
    string t2 = "y";
    cout << s.findTheDifference(s2, t2) << endl; // y
}