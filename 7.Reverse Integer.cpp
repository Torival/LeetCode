class Solution {
public:
    int reverse(int x) {
        long long num = 0;
        int x1 = abs(x);

        for(long long i=1; i<=x1; i*=10) {
            num = 10*num + x1/i%10;
            if(num > INT_MAX) return 0;
        }
        return x > 0 ? num :-num;
    }
};
