class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int a[10];
        int num = x, top = -1;
        
        while(num) {
            a[++top] = num % 10;
            num /= 10;
        }
        
        while(x) {
            if(a[top--] != x%10) return false;
            x /= 10;
        }
        
        return true;
    }
};