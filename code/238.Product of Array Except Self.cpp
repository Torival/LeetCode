class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long a = 1;
        int flag = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i]) a *= nums[i];
            else flag++;
            if(flag == 2) break;
        }
        
        if(flag >= 2) {
            for(int i=0; i<nums.size(); i++)
                nums[i] = 0;
        } else if(flag == 1) {
            for(int i=0; i<nums.size(); i++) {
                if(nums[i]) nums[i] = 0;
                else nums[i] = a;
            }
        } else {
            for(int i=0; i<nums.size(); i++)
                nums[i] = a/nums[i];
        }
        
        return nums;
    }
};
