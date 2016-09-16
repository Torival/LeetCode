class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v(num + 1, 0);
        int size = 1;
        
        while(num) {
            for(int i = 0; i < size && num; i++){
                v[size+i] = v[i] + 1;
                num--;
            }
            size *= 2;
        }
        return v;
    }
};
