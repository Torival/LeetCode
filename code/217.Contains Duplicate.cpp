class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int count = nums.size();
        if(!count) return false;
        int min = nums[0], max = nums[0];
        for(int i=1; i<count; i++) {
            if(max < nums[i]) max = nums[i];
            if(min > nums[i]) min = nums[i];
        }
        
        int *a = new int[max-min+1]();
        for(int i=0; i<count; i++) {
            if(!a[nums[i]-min]) a[nums[i]-min]++;
            else return true;
        }
        
        return false;
    }
};
