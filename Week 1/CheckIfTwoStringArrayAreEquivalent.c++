/* kiểm tra 2 mảng chuỗi giống nhau khi gộp lại không */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string s1,s2;
        for(string s:word1)
        {
            s1 += s;
        }
        for(string s:word2)
        {
            s2 += s;
        }
        return s1 == s2;
    }
};

int main()
{
    Solution s;
    vector<string> word1 = {"ab", "c"};
    vector<string> word2 = {"a", "bc"};
    cout << s.arrayStringsAreEqual(word1, word2) << endl; // true

}