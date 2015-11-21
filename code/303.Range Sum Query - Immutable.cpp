class NumArray {
public:
    NumArray(vector<int> &nums) {
        int temp = 0;
        for(int i=0; i<nums.size(); i++) {
            temp += nums[i];
            num.push_back(temp);
        }
    }

    int sumRange(int i, int j) {
        if(i>num.size() || num.size()<j) return 0;
        if(!i) return num[j];
        else return num[j] - num[i-1];
    }
private:
    vector<int> num;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
