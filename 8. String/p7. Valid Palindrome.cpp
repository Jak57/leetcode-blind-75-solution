class Solution {
public:
    bool isPalindrome(string s) {
        int n, i, j;
        string clean = "";
        n = s.size();
        for (i = 0; i < n; i++) {
            char ch = s[i];
            if (ch >= 'A' && ch <= 'Z') 
                clean += (ch - 'A' + 'a');
            else if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                clean += ch;
        }
        
        n = clean.size();
        if (n <= 1)
            return true;
        
        i = 0;
        j = n-1;
        
        while (i < j) {
            if (clean[i] != clean[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
};
