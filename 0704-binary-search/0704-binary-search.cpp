class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        for(int i: nums)
        {
            
            if(i==target) return count;
            count++;
        }
        return -1;      
    }
    
};