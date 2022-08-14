class Solution {
public:
    // TLE
    // int climb(int n) {
    //     // recursive
    //     if (n == 0) return 1;
    //     if (n == 1) return 1;
    //     if (n == 2) return 2;
    //     if (n == 3) return 3;
    //     int one = climb(n-1);
    //     int two = climb(n-2);
    //     return one+two;
    // }
    int climbStairs(int n) {
        // Fibonacci
        int a = 1, b = 1;
        int c;
        for(int i = 0 ; i < n-1 ; i++) {
            c = a;
            a = a + b;
            b = c;
        }
        return a;
        // return climb(n);
    }
};
