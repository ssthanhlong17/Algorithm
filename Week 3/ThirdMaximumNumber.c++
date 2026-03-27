/* Tìm số lớn thứ ba trong mảng */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        long max1 = -2147483649;
        long max2 = -2147483649;
        long max3 = -2147483649;
        for(int i:nums)
        {
            if(i>max1)
            {
                max3=max2;
                max2=max1;
                max1=i;
            }
            if(i>max2 && i<max1)
            {
                max3=max2;
                max2=i;
            }
            if(i>max3 && i<max2)
            {
                max3=i;
            }
        }
        return (max3 == -2147483649) ? (int)max1:(int)max3;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {3,2,1};
    cout << s.thirdMax(nums1) << endl; // 1
    vector<int> nums2 = {1,2};
    cout << s.thirdMax(nums2) << endl; // 2
    vector<int> nums3 = {2,2,3,1};
    cout << s.thirdMax(nums3) << endl; // 1
}