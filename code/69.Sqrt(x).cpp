class Solution {
public:
    int mySqrt(int x) {
        if(x <= 0) return 0;
        int low = 0, high = x;
        long long a = (x+0)/2;
        
        while(low <= high) {
            if(a*a == x) return a;
            else if(a*a > x) high = a - 1;
            else low = a + 1;
            
            a = (low+high)/2;
        }
        return a;
    }
};
