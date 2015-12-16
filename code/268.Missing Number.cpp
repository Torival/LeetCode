class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long m = (nums.size()+1)*nums.size()/2;
        for(int i=0; i<nums.size(); i++)
            m -= nums[i];
        return m;
    }
};
