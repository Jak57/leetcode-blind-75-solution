// https://www.youtube.com/watch?v=UcoN6UjAI64&ab_channel=NeetCode

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i, res = 0, bit;
        for (i = 0; i < 32; i++) {
            bit = n & 1;
            n = n >> 1;
            res = res | (bit << (31-i));
        }
        return res;
    }
};
