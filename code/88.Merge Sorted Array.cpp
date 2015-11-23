class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!n) return ;
        if(!m) {
            nums1 = nums2;
            return;
        }
        
        vector<int> vec;
        int k = 0, i = 0, j = 0;
        
        while(i<m && j<n) {
            if(nums2[j] < nums1[i]) {
                vec.push_back(nums2[j++]);
            } else {
                vec.push_back(nums1[i++]);
            }
        }
        while(i < m) vec.push_back(nums1[i++]);
        while(j < n) vec.push_back(nums2[j++]);
        nums1 = vec;
    }
};
