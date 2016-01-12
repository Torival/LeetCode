class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        vector<int> vec({0,0});
        
        for(int i = 0; i < nums.size(); i++) {
            temp ^= nums[i];
        }
        temp &= -temp;
        
        for(int i = 0; i < nums.size(); i++) {
            if(temp & nums[i]) vec[0] ^= nums[i];
            else vec[1] ^= nums[i];
        }
        
        return vec;
    }
};
