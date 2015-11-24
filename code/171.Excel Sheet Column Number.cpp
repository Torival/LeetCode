class Solution {
public:
    int titleToNumber(string s) {
        int num = s.length();
        if(!num) return 0;
        int count = 0;
        for(int i=0; i<num; i++) {
            count = 26*count + s[i] - 'A' + 1;
        }
        return count;
    }
};
