class Solution {
public:
    //分而治之，折半计算
    double myPow(double x, int n) {
        if(x == 0) return 0;
        
        if(n == 0) return 1;
        else if(n == -1) return 1/x;
        else if(n == 1) return x;
        else if(n & 1) {
            double temp = myPow(x,(n-1)/2);
            return temp*temp*x;
        }
        else {
            double temp = myPow(x,n/2);
            return temp*temp;
        }
    }
};
