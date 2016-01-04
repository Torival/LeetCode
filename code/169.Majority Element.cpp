class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> map;
        for(int i=0; i<nums.size(); i++) {
            map[nums[i]]++;
        }
        for(auto it=map.begin(); it!=map.end(); it++) {
            if(it->second > nums.size()/2)
                return it->first;
        }
        return 0;
    }
};
