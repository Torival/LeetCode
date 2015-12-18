class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(!m || !n) return false;
        
        int low = 0, high = m-1;
        int mid;
        while(low <= high) {
            mid = (low + high)/2;
            if(matrix[mid][0] <= target && target <= matrix[mid][n-1]) break;
            else if(matrix[mid][0] < target) low = mid + 1;
            else high = mid -1;
        }
        if(low > high) return false;
        low = 0, high = n-1;
        int mid2;
        while(low <= high) {
            mid2 = (low + high)/2;
            if(matrix[mid][mid2] == target) return true;
            else if(matrix[mid][mid2] < target) low = mid2 + 1;
            else high = mid2 -1;
        }
        return false;
    }
};
