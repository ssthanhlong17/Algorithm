/* Merge Sorted Array - với 2 mảng đã sắp xếp gộp lại thành một mảng
theo chiều tăng dần*/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    template<typename T, typename U>
    void merge(vector<T>& nums1, int m, vector<U>& nums2, int n) 
    {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(j>=0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};

int main()
{
    Solution s1;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    s1.merge(nums1, 3, nums2, 3);
    for(auto i: nums1)
    {
        cout << i << " ";
    }
    cout << endl;

    // Test với kiểu dữ liệu int và double hàm ngầm mặc định int = double và in ra int
    vector<int> nums3 = {1,2,3,0,0,0};
    vector<double> nums4 = {2.2,5.5,6.6};
    s1.merge(nums3, 3, nums4, 3);
    for(auto a: nums3)
    {
        cout << a << " ";
    }
    cout << endl;

     // Test với kiểu dữ liệu double và int hàm ngầm mặc định double = int và in ra double
    vector<double> nums5 = {1.1,2.0,3.3,0,0,0};
    vector<int> nums6 = {2,5,6};
    s1.merge(nums5, 3, nums6, 3);
    for(auto a: nums5)
    {
        cout << a << " ";
    }
    cout << endl;
}