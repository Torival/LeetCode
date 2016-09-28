// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1, mid;
        int flag;
        
        for(; ;) {
            mid = (low + n) / 2;
            
            if((flag = guess(mid)) > 0)
                low = mid + 1;
            else if(flag < 0)
                n = mid - 1;
            else
                break;
        }
        
        return mid;
    }
};
