/* Kiểm tra mảng có chứa phần tử trùng lặp không */
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int,int> m;
        for(int i:nums)
        {
            m[i]++;
            if(m[i] > 1) return true;
        }
        return false;
    }
};


int main()
{
    Solution s;
    vector<int> nums1 = {1,2,3,1};
    cout << s.containsDuplicate(nums1) << endl; // true
    vector<int> nums2 = {1,2,3,4};
    cout << s.containsDuplicate(nums2) << endl; // false
    vector<int> nums3 = {1,1,1,3,3,4,3,2,4,2};
    cout << s.containsDuplicate(nums3) << endl; // true
}