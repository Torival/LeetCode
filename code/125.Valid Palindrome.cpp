class Solution {
public:
    bool isPalindrome(string s) {
        int pre = 0;
        int post = s.length()-1;

        while(pre<=post) {
            while(post>=pre && ('0'>s[pre]|| (s[pre]>'9'&&'A'>s[pre])  || ('Z'<s[pre]&&s[pre]<'a') || s[pre]>'z'))
                pre++;
            if(s[pre]>='a') s[pre] -= 32;

            while(post>=pre && ('0'>s[post]|| (s[post]>'9'&&'A'>s[post])  || ('Z'<s[post]&&s[post]<'a') || s[post]>'z'))
                post--;
            if(s[post]>='a') s[post] -= 32;
            
            if(pre >= post) return true;
            if(s[pre] != s[post]) return false;
            else pre++,post--;
        }
        return true;
    }
};
