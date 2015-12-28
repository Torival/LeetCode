class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        if(nums[start] <= nums[end])    return nums[start];
        
        int mid;
        while(start < end) {
            mid = (start+end)/2;
            if(nums[mid] > nums[end])
                start = ++mid;
            else
                end = mid;
        }
        return nums[mid];
    }
};
