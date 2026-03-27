/* Tổng các phần tử nhỏ nhất trong từng cặp */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max=0;
        for(int i=0; i<nums.size(); i+=2){
            max += nums[i];
        }
        return max;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1,4,3,2};
    cout << s.arrayPairSum(nums1) << endl; // 4
    vector<int> nums2 = {6,2,6,5,1,2};
    cout << s.arrayPairSum(nums2) << endl; // 9
}