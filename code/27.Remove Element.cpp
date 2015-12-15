class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        while(count != nums.size()) {
            if(nums[count] == val) nums.erase(nums.begin()+count);
            else count++;
        }
        return count;
    }
};
