class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        
        vector<int> vec(num1.size() + num2.size(), 0);
        int carry = 0;
        for(int i = 0; i < num1.size(); i++) {
            int dit1 = num1[num1.size()-1-i] - '0';
            for(int j = 0; j< num2.size(); j++) {
                int dit2 = num2[num2.size()-1-j] - '0';
                vec[i+j+1] += (dit1*dit2 + vec[i+j]) / 10;
                vec[i+j] = (dit1*dit2 + vec[i+j]) % 10;
            }
        }
        
        int start = vec.size() - 1;
        while(vec[start] == 0)
            start--;
        
        string slt = "";
        while(start >= 0)
            slt += to_string(vec[start--]);
        
        return slt;
    }
};