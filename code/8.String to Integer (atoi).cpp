class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0) return 0;
        
        int start = 0;
        int flag = 1;
        // 除去前导空格
        while(str[start] == ' ') start++;
        
        // 判断数字转换后的正负
        if(str[start] == '-') {
            flag = -1, start++;
        } else if(str[start] == '+') {
            start++;
        }
        
        long long num = 0;
        for(; start < str.size(); start++) {
            if(isdigit(str[start]))
                num = num * 10 + str[start] - '0';
            else
                break;

            // int溢出，直接返回
            if(num > INT_MAX) 
                return flag == 1 ? INT_MAX : INT_MIN;    
        }
        
        return flag == 1 ? num : - num;
    }
};