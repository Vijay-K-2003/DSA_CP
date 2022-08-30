class Solution {
public:
    int reverse(int x) {
        // int sol = 0;
        // while (x) {
        //     int dig = x % 10;
        //     x = x / 10;
        //     if (sol > (INT_MAX/10) or (sol == INT_MAX/10 and dig >= INT_MAX % 10))
        //         return 0;
        //     if (sol < (INT_MIN/10) or (sol == INT_MIN/10 and dig <= INT_MIN % 10))
        //         return 0;
        //     sol = sol*10 + dig;
        // }
        // return sol;
        long sol = 0;
        while (x) {
            sol = sol*10 + x%10;
            if (sol > INT_MAX || sol < INT_MIN) return 0;
            x = x/10;
        }
        return (int)sol;
    }
};
