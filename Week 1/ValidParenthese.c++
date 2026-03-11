/* chương trình kiểm tra chuỗi ngoặc hợp lệ */

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
        stack<string> st;
        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
            {
                st.push(string(1, c));
            }
            else
            {
                if(st.empty()) return false;
                string top = st.top();
                st.pop();
                if( (c == ')' && top != "(") ||
                    (c == '}' && top != "{") || 
                    (c == ']' && top != "[") )
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution s;
    string s1 = "()[]{}";
    cout << s.isValid(s1) << endl; // true

    string s2 = "([)]";
    cout << s.isValid(s2) << endl; // false

    string s3 = "{[]}";
    cout << s.isValid(s3) << endl; // true
}