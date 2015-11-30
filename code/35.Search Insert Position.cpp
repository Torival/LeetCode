class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size()-1;
        if(high == -1) return 0;
        else if(nums[0] > target) return 0;
        else if(nums[high] < target) return high+1;
        
        int low = 0;
        int mid;
        while(low <= high) {
            mid = (low + high) >> 1;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
