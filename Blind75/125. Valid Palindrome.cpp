class Solution {
public:
    bool isPalindrome(string s) {
        string out = "";
        for (int i = 0 ; i < s.size(); i++){
            char c = tolower(s[i]);
            if((c >= 'a' and c <= 'z') or (c >= '0' and c <= '9'))
                out += c;
        }
        int n = out.size();
        for (int i = 0 ; i < n/2; i++) {
            if (out[i] != out[n-i-1])
                return false;
        }
        return true;
    }
};
