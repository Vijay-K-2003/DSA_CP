class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) return false;
        if (s[0] == ')' or s[0] == ']' or s[0] == '}') return false;
        stack<char> c;
        for (int i = 0 ; i < s.size() ; i++) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (c.empty()) {
                    return false;
                }
                if (s[i] == ')' && c.top() != '(') {
                    return false;
                }
                if (s[i] == '}' && c.top() != '{') {
                    return false;
                }
                if (s[i] == ']' && c.top() != '[') {
                    return false;
                }
                c.pop();
            } else {
                c.push(s[i]);
            }
        }
        if (c.empty())
            return true;
        return false;
    }
};
