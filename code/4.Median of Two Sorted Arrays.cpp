class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        if(total & 0x01)
            return findKth(nums1, 0, nums2, 0, total / 2 + 1);
        else 
            return (findKth(nums1, 0, nums2, 0, total / 2) + 
                findKth(nums1, 0, nums2, 0, total / 2 + 1)) / 2.0;
    }
    
    double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int kth) {
        if(nums1.size() - start1 > nums2.size() - start2)
            return findKth(nums2, start2, nums1, start1, kth);
        
        if(nums1.size() - start1 == 0) 
            return nums2[kth + start2 - 1];
        
        if(kth == 1)
            return min(nums1[start1], nums2[start2]);
            
        int pa = min(kth / 2, (int)nums1.size() - start1), pb = kth - pa;
        
        if(nums1[start1 + pa - 1] < nums2[start2 + pb - 1])
            return findKth(nums1, start1 + pa, nums2, start2, kth - pa);
        else if(nums1[start1 + pa - 1] > nums2[start2 + pb - 1])
            return findKth(nums1, start1, nums2, start2 + pb, kth - pb);
        else
            return nums1[start1 + pa - 1];
            
        return 0.0;
    }
};
