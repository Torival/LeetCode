class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <= 2) {
            for(int i=0; i<len; i++) {
                if(nums[i] == target) return i;
                if(i == len - 1) return -1;
            }
        }
        int low = 0, high = len - 1;
        int mid = 0, cycle = 0;
        if(nums[low] > nums[high]) {
            while(low < high) {
                cycle = (low + high) >> 1;
                if(low == high - 1) break;
                if(nums[low] > nums[cycle]) high = cycle;
                else low = cycle; 
            }
            low = ++cycle, high = cycle - 1;
        }
        if(target > nums[high] || target < nums[low]) return -1;

        int move = len - 1;
        while(nums[low] <= nums[high]) {
            mid = (low + (move = move >> 1))%len;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) high = (len + mid - 1)%len;
            else low = (len + mid + 1)%len;
        }
        return -1;
    }
};
