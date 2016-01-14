class Solution {
public:
    bool isValid(string s) {
        int top = 0;
        int k;
        char a[s.length()];

        for(int i=0; i<s.length(); i++) {
            if(!top) 
                a[top++] = s[i];
            else {
                k = a[top-1]-s[i];
                if(k==1 || k==-1 || k==2 || k==-2) top--;
                else a[top++] = s[i];
             }
        }
        return top > 0 ? false : true;
    }
};
