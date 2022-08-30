class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> out(numRows, "");
        int st = 0;
        int sign = 1;
        for (int i = 0; i < s.size() ; i++) {
            out[st] += s[i];
            st = st+sign;
            if (st+1 == numRows or st == 0) {
                sign = -sign; 
            }
        }
        string ans = "";
        for (string a : out) {
            ans += a;
        }
        return ans;
    }
};
