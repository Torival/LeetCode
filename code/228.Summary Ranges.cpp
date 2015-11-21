class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        if(!nums.size()) return vec;
        
        string s = to_string(nums[0]);
        
        if(nums.size() == 1) { 
            vec.push_back(s);
            return vec;
        }
        
        int index = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1]+1) {
                index++;
                continue;
            }
            if(index) s = s + "->" + to_string(nums[i-1]);
            index = 0;
            vec.push_back(s);
            s = to_string(nums[i]);
        }
        
        if(nums[nums.size()-1] == nums[nums.size()-2]+1) {
            s = s + "->" + to_string(nums[nums.size()-1]);
            vec.push_back(s);
        } else {
            vec.push_back(to_string(nums[nums.size()-1]));
        }
    }
};
