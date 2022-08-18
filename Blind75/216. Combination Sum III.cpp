class Solution {
public:
    vector<vector<int>> res;
    void cs3(vector<int>& c, int k, int n, int start) {
        if (k == c.size()) {
            if (n == 0) res.push_back(c);
            return;
        }
        for(int i = start; i <= 9 ; i++) {
            c.push_back(i);
            cs3(c, k, n-i, i+1);
            c.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> c;
        cs3(c, k, n, 1);
        return res;
    }
};
