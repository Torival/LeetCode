class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return 0;
        if(n <= 6) return n;
        
        int *num = new int[n];
        int l2 = 0, l3 = 0, l5 = 0;
        int count = 0;
        int temp;
        num[count++] = 1;
        while(count < n) {
            temp = num[l2]*2 < num[l3]*3 ? 2*num[l2] : 3*num[l3];
            num[count++] = temp < num[l5]*5 ? temp : 5*num[l5];
            if(num[count-1] == num[l2]*2) l2++;
            if(num[count-1] == num[l3]*3) l3++;
            if(num[count-1] == num[l5]*5) l5++;
        }
        return num[count-1];
    }
};
