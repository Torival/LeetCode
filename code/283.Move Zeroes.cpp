class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int num = nums.size();
        if(!num) return ;
        vector<int> vec;
        int count = 0;
        for(int i=0; i<num; i++) {
            if(nums[i]) { 
                vec.push_back(nums[i]);
                count++;
            }
        }
        while(count != num) {
            vec.push_back(0);
            count++;
        }
        nums = vec;
    }
};
