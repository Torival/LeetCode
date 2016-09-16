class Solution {
public:
    void reverseWords(string &s) {
        int count = s.length();
        if(!count) return ;
        
        string str = "";
        for(int i = count - 1; i >= 0; i--){
            if(s[i] != ' ') {
                str += s[i];
            } else {
                if(!str.empty()) {
                    reverse(str.begin(), str.end());
                    s += str + " ";
                    str = "";
                }
            }
        }
        
        reverse(str.begin(), str.end());
        
        if(!str.empty()) 
            s += str;
        if(count != 0) 
            s.erase(0, count);
        if(s[s.length()-1] == ' ') 
            s.erase(s.find_last_not_of(" ") + 1);

    }
};
