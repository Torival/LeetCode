class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        
        int m = 9;
        int count = 1;
        int n1 = n, m1 = 9;
        
        while((n = n - count*m) > 0 && count < count*m) {
            count++;
            m1 = m;
            m = 10 * m;
            n1 = n;
            if(m < m1) break;
        }

        if(!(n1 % count))
            return (n1 / count + m1 + m1 / 9 - 1) % 10;
        else 
            return (n1 / count + m1 + m1 / 9) / (int)pow(10, count - n1 % count) %10;
    }
};
