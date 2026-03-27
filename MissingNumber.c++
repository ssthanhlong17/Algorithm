/* Tìm số bị thiếu trong mảng */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> check(n+1,false);
        for(int i:nums)
        {
            check[i]=true;
        }
        for(int i=0; i<=n; i++)
        {
            if(check[i]==false)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3,0,1};
    cout << s.missingNumber(nums1) << endl; // 2
    vector<int> nums2 = {0,1};
    cout << s.missingNumber(nums2) << endl; // 2
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    cout << s.missingNumber(nums3) << endl; // 8
}