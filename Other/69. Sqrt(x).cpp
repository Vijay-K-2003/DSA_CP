class Solution {
public:
    int mySqrt(int x) {
        if (x == 1 || x == 0)   return x;
        long l = 1, r = x/2, sol, m, ans;
        while (l <= r) {
            m = (l+r)/2;
            sol = m*m;
            if (sol == x) return m;
            if (sol <= x) {
                ans = m;
                l = m+1;
            } 
            else r = m - 1;
        }
        return ans;
    }
};
