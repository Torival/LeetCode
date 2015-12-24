class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int count = 0;
        while(m != n) {
            if(!m) return 0;
            
            m >>= 1;
            n >>= 1;
            count++;
        }
        return m << count;
    }
};
