class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count = digits.size();
        
        digits[--count] += 1;
        for(count; count >= 0 ; count--) {
            if(digits[count] == 10 && count != 0) {
                digits[count] = 0;
                digits[count - 1] += 1;
            } else 
                break;
        }
        if(digits[0] == 10){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
};
