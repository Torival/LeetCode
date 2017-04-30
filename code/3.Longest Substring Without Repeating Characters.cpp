class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vec(256, -1);
        int len = 0;
        int start = -1;
        
        for(int i = 0; i < s.size(); ++i) {
            if(vec[s[i]] > start)
                start = vec[s[i]];
            
            vec[s[i]] = i;
            len = max(len, i - start);
        }
        
        return len;
    }
};