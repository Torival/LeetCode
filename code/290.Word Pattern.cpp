class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len = str.length();
        if(!len) return false;
        map<string, char> table;
        set<char> st;
        
        string s;
        int j = 0;
        str += ' ';
        for(int i=0; i<len+1; i++) {
            if(str[i] == ' ') {
                bool tbfind = (table.find(s) == table.end());
                bool stfind = (st.find(pattern[j])==st.end());
                if(tbfind && stfind) {
                    st.insert(pattern[j]);
                    table[s] = pattern[j];
                } else if(table.find(s)->second != pattern[j])
                    return false;
                else if(!tbfind && stfind)
                    return false;
                s = "", j++;
            }
            else
                s += str[i];
        }
        if(j != pattern.length()) return false;
        return true;
    }
};
