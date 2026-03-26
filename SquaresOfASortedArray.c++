/* Tìm bình phương của các phần tử trong mảng đã sắp xếp */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int n=nums.size();
        vector<int> ans(n);

        int left=0,right=n-1,pos=n-1;

        while(left<=right){

            if(abs(nums[left])>abs(nums[right])){
                ans[pos--]=nums[left]*nums[left];
                left++;
            }
            else{
                ans[pos--]=nums[right]*nums[right];
                right--;
            }
        }

        return ans;
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {-4,-1,0,3,10};
    vector<int> ans1 = s.sortedSquares(nums1);
    for(int i=0; i<ans1.size(); i++)
        cout << ans1[i] << " "; // 0 1 9 16 100
    cout << endl;
    vector<int> nums2 = {-7,-3,2,3,11};
    vector<int> ans2 = s.sortedSquares(nums2);
    for(int i=0; i<ans2.size(); i++)
        cout << ans2[i] << " "; // 4 9 9 49 121
}