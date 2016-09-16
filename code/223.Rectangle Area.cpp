class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int re1l = abs(A - C), re1w = abs(B - D);
        int re2l = abs(E - G), re2w =  abs(F - H);
        
        int len1, len2;
        
        if(A < E && G < C) 
            len1 = re2l;
        else if(E < A && C < G)
            len1 = re1l;
        else 
            len1 = re1l + re2l - (abs(A - G) > abs(E - C) ? abs(A - G) : abs(E - C));
        
        if(B < F && H < D)
            len2 = re2w;
        else if(F < B && D < H)
            len2 = re1w;
        else
            len2 = re1w + re2w - (abs(B - H) > abs(D - F) ? abs(B - H) : abs(D - F));
        
        if(len1 < 0 || len2 < 0) return re1l*re1w + re2l*re2w;
        return re1l*re1w + re2l*re2w - len1*len2;
    }
};
