class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1 ; i < amount+1 ; i++) {
            for(int c: coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], 1 + dp[i-c]);
                }
            }
        }
        if(dp[amount] != INT_MAX)   return dp[amount];
        else                        return -1;
    }
};
