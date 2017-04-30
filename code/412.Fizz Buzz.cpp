class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec;
        string s;
        for(int i = 1; i <= n; i++) {
            s = "";
            if(!(i % 3)) s += "Fizz";
            if(!(i % 5)) s += "Buzz";
            if(s == "") s += to_string(i);
            
            vec.push_back(s);
        }
        
        return vec;
    }
};
