class Solution {
public:
    string addBinary(string a, string b) {
        int lenb = b.length();
        int lena = a.length();
        
        if(!lena) return b;
        if(!lenb) return a;
        
        int lenc = lenb > lena ? lenb : lena;
        string c;
        int i = -1;
        while(lenc > ++i) { 
            if(c[i] != '1') c.insert(c.end(),'0'); 
            
            if(lena && lenb) c[i] = b[--lenb] + a[--lena] - 2*'0' + c[i];
            else if(lena) c[i] = a[--lena] - '0' + c[i];
            else if(lenb) c[i] = b[--lenb] - '0' + c[i];
            
            if(c[i] >= '2') {
                c[i] -= 2;
                c.insert(c.end(),'1');
            }
        }
        reverse(c.begin(), c.end());
        return c;
    }
};
