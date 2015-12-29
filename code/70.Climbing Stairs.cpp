class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) return 0;
        int f1 = 1, f2 = 2;
        for(int i=2; i<n; i++) {
            if(!(i%2)) f1 = f1 + f2;
            else f2 = f1 + f2;
        }
        return n%2 ? f1 : f2;
    }
};
