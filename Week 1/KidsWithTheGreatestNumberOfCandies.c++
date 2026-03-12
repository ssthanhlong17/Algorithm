/* Kiểm tra số lượng kẹo nhiều nhất sau khi thêm kẹo vào */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> status;
        int maxCandy = 0;
        for(int i : candies)
        {
            if(i >maxCandy) maxCandy = i;
        }
        for(int i :candies)
        {
            if(i + extraCandies >= maxCandy) status.push_back(true);
            else status.push_back(false);
        }
        return status;
    }
};

int main()
{
    Solution s;
    vector<int> candies = {2,3,5,1,3};
    int extraCandies = 3;
    vector<bool> status = s.kidsWithCandies(candies, extraCandies);
    for(bool b : status)
    {
        if(b == true) cout << "true ";
        else cout << "false ";
    }
}
