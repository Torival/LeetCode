class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(!nums.size() || target<nums[0]) return vector<int>({-1,-1});
        vector<int> vec;
        int size = nums.size();
        int low = 0, high = size - 1;
        int mid;
        //find the starting position 
        while(low <= high) {
            mid = (low + high)/2;
            if(nums[mid] == target && (nums[mid-1]<target || mid == 0)) {
                vec.push_back(mid);
                break;
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        if(!vec.size()) return vector<int>({-1,-1});
        low = 0, high = size - 1;
        //find the ending position 
        while(low <= high) {
            mid = (low + high)/2;
            if(nums[mid] == target && (nums[mid+1]>target || mid == size-1)) {
                vec.push_back(mid);
                break;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return vec;
    }
};
