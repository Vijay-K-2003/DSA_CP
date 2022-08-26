class Solution {
public:
    vector<int> count(int n) {
        vector<int> ans(10, 0);
        while (n > 0) {
            ans[n%10]++;
            n = n/10;
        }
        return ans;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> v = count(n);
        for (int i = 0 ; i < 31 ; i++) {
            if (v == count(1 << i)) {
                return true;
            }
        }
        return false;
    }
};
