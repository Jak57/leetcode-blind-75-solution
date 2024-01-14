// https://www.youtube.com/watch?v=5Km3utixwZs&t=465s&ab_channel=NeetCode

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n > 0) {
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
};
