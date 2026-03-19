/*Loại bỏ ký tự in hoa và in thường để tạo chuỗi tốt hơn */

#include <iostream>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    string makeGood(string s) {
        stack <char> st;
        for(int i=0; i<s.size(); i++)
        {
            if(st.empty() || (abs(st.top()-s[i]) != 32)) st.push(s[i]);
            else st.pop();
            
        }
        string res = "";
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.makeGood("leEeetcode") << endl; // leetcode
    cout << s.makeGood("abBAcC") << endl; // ""
    cout << s.makeGood("s") << endl; // "s"
}