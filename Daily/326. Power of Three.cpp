class Solution {
public:
    bool isPowerOfThree(int n) {
        // 27 ms
        if (n < 1) return false;
        while(n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
        // 55ms
        // return n > 0 && 1162261467 % n == 0;
    }
};
