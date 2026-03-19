/* Biểu diễn Stack thông qua Queue */
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        int pop = q1.front();
        q1.pop();
        return pop;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};
int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    cout << s.top() << endl; // 2
    cout << s.pop() << endl; // 2
    cout << s.empty() << endl; // false
}