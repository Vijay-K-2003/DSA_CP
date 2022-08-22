class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n == INT_MAX or n == INT_MIN or n == 0) return false;
        while (n) {
            if (n % 4 != 0 and n != 1) return false;
            n = n/4;
        }
        return true;
    }
};
