class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500},{'M', 1000}
        };
        int count = s.length();
        int num = mp[s[count - 1]];
        
        for(int i = count - 2; i >= 0; i--) {
            num += mp[s[i]] >= mp[s[i+1]] ? mp[s[i]] : -mp[s[i]];
        }
        
        return num;
   }
};