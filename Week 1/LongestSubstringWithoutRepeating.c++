/* Tìm độ dài chuỗi con dài nhất không chứa ký tự lặp lại */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        int left = 0, maxLength = 0;
        vector<int> count(128,-1);
        for(int right = 0; right < s.size(); right++)
        {
            if(count[s[right]] >= left)
            {
                left = count[s[right]] +1; 
            }
            count[s[right]] = right;
            maxLength = max(maxLength, right -left +1);
        }
        return maxLength;
    }
};
int main()
{
    Solution s;
    string s1 = "abcabcbb";
    cout << s.lengthOfLongestSubstring(s1) << endl; // 3

    string s2 = "bbbbb";
    cout << s.lengthOfLongestSubstring(s2) << endl; // 1

    string s3 = "pwwkew";
    cout << s.lengthOfLongestSubstring(s3) << endl; // 3
}