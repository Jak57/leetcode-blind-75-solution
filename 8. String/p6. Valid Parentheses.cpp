// Hashmap

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char ch;
        int n, i;
        n = s.size();
        
        for (i = 0; i < n; i++) {
            ch = s[i];
            if (stk.empty()) {
                stk.push(ch);
            } else {
                if ((stk.top() == '(' && ch == ')') || (stk.top() == '{' && ch == '}') || (stk.top() == '[' && ch == ']'))
                    stk.pop();
                else
                    stk.push(ch);
            }
        }
        return (stk.size() == 0);
    }
};
