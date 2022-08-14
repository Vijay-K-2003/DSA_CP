class Solution {
public:
    // TLE : Recursive Solution
    // int lcs(string s1, string s2, int n, int m) {
    //     // Base Case
    //     if (n == 0 || m == 0) return 0;
    //     // SOL
    //     if (s1[n-1] == s2[m-1]) {
    //         return 1 + lcs(s1, s2, n-1, m-1);
    //     } else {
    //         return max(lcs(s1, s2, n-1, m), lcs(s1, s2, n, m-1));
    //     }
    // }
    
    // TLE : Recursize + Memoization
    // int memo[1001][1001];
    // int lcs(string s1, string s2, int n, int m) {
    //     // Base Case
    //     if (n == 0 || m == 0) return 0;
    //     // SOL
    //     int sol = 0;
    //     if (memo[n][m] != -1) return memo[n][m];
    //     if (s1[n-1] == s2[m-1]) {
    //         sol = 1 + lcs(s1, s2, n-1, m-1);
    //         memo[n][m] = sol;
    //     } else {
    //         int sol1, sol2;
    //         sol1 = lcs(s1, s2, n-1, m);
    //         sol2 = lcs(s1, s2, n, m-1);
    //         sol = max(sol1, sol2);
    //         memo[n][m] = sol;
    //     }
    //     return sol;
    // }
    
    // BEST : 28ms 10.6MB 
    int memo[1001][1001];
    int lcs(string s1, string s2, int n, int m) {
        for (int i = 1 ; i < n+1 ; i++) {
            for (int j = 1; j < m+1 ; j++) {
                if(s1[i-1] == s2[j-1]) {
                    memo[i][j] = 1 + memo[i-1][j-1];
                }
                else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }
        }
        return memo[n][m];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // recursive
        // return lcs(text1, text2, text1.size(), text2.size());
        // recursive + memoization
        // memset(memo, -1, sizeof(memo));
        // return lcs(text1, text2, text1.size(), text2.size());
        
        for(int i = 0 ; i < text1.size()+1 ; i++) {
            for (int j = 0 ; j < text2.size()+1 ; j++) {
                if (i == 0 || j == 0) {
                    memo[i][j] = 0;
                }
            }
        }
        return lcs(text1, text2, text1.size(), text2.size());
    }
};
