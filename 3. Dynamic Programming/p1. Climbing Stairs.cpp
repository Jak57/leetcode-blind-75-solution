// Fibonacci Sequence

class Solution {
public:
    int climbStairs(int n) {
        int fib[100];
        fib[0] = fib[1] = 1;
        
        if (n == 1)
            return 1;
        
        for (int i = 2; i <= n; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[n];
    }
};
