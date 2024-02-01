// 1.

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

// 2.

class Solution {
public:
    bool isValid(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'));
    }
    
    bool isPalindrome(string s) {
        int n, i, j;
        char ch1, ch2;
        n = s.size();

        for (i = 0; i < n; i++) {
            char ch = s[i];
            if (ch >= 'A' && ch <= 'Z')
                s[i] = s[i] - 'A' + 'a';
        }
        
        i = 0;
        j = n-1;
        while (i < j) {
            ch1 = s[i];
            ch2 = s[j];
            if (!isValid(ch1))
                i++;
            if (!isValid(ch2))
                j--;
            
            if (isValid(ch1) && isValid(ch2)) {
                if (ch1 != ch2)
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
};
