class Solution {
public:
    string reverseString(string s) {
        int len = s.length();
        
        if(len == 0) return s;
        for(int i = 0; i < len / 2; i++)
            swap(s[i], s[len-1-i]);

        return s;
    }
};
