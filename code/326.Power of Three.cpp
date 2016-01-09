class Solution {
public:
    bool isPowerOfThree(int n) {  //1162261467 is max 3^n of int
        return n<=0 ? false : 1162261467%n == 0;
    }
};
