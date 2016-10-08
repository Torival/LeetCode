class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int start, end, mid;
        int find = 0;
        vector<int> v(2, 1);
        
        for(int i = 0; i < size; i++) {
           start = i + 1, end = size - 1;
           while(start <= end) {
               mid = (start + end) / 2;
               if(numbers[mid] == target - numbers[i]) {
                   find = 1;
                   break;
               }
               else if(numbers[mid] > target - numbers[i])
                   end = mid - 1;
               else
                   start = mid + 1;
           }
           if(find) {
               v[0] += i;
               v[1] += mid;
               break;
           }
        }
        
        return v;
    }
};
