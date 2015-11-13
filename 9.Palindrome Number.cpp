class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = x;
        stack<int> st;
        while(num) {
            st.push(num % 10);
            num /= 10;
        }
        
        while(x) {
            if(st.top() != x%10) return false;
            st.pop();
            x /= 10;
        }
        
        return true;
    }
};
