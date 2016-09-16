class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(!(k %= nums.size())) return ;
        
        int index = 0, count = 0;
        int temp = nums[0];
        
        for(int i=0; i<nums.size(); i++) {
            if(count == index) {
                temp = nums[++count];
                index++;
            }
            
            index = (index+k)%nums.size();
            swap(temp, nums[index]);
        }
    }
}; 
