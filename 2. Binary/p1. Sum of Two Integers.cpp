// https://www.youtube.com/watch?v=gVUrDV4tZfY&t=592s&ab_channel=NeetCode

class Solution {
public:
    int getSum(int a, int b) {
        int _xor, _and;
        while (true) {
            _xor = a^b;
            _and = (a&b) << 1;
            if (_and == 0)
                break;
            
            a = _xor;
            b = _and;
        }
        return _xor;
    }
};
