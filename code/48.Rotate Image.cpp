class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int low = 0, high = matrix.size()-1;
        int temp;
        while(low < high) {
            for(int i=0; i<high-low; i++) {
                temp = matrix[low][low+i];
                matrix[low][low+i] = matrix[high-i][low];
                matrix[high-i][low] = matrix[high][high-i];
                matrix[high][high-i] = matrix[low+i][high];
                matrix[low+i][high] = temp;
            }
            low++, high--;
        }
    }
};
