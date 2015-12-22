class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x = 0;
        uint32_t temp;
        for(int i=0; i<32; i++) {
            x = (x << 1) + n % 2;
            n = n >> 1;
        }
        return x;
    }
};
