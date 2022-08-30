class Solution {
public:
// TLE Recursive Solution Exponential Time Complexity
// INPUT:
// "dinitrophenylhydrazine"
// "benzalphenylhydrazone"
//     int editDistance(string s1, string s2, int m, int n)
//     {
//         if (m == 0)
//             return n;

//         if (n == 0)
//             return m;

//         if (s1[m - 1] == s2[n - 1])
//             return editDistance(s1, s2, m - 1, n - 1);
        
//         return 
//             1 + 
//             min(
//             {
//                 editDistance(s1, s2, m, n-1), 
//                 editDistance(s1, s2, m-1, n), 
//                 editDistance(s1, s2, m-1, n-1)
//             });
//     }
    
    // Memoize : Accepted : 135ms 80.7MB
//     int editDistance(string s1, string s2, int m, int n, vector<vector<int>>& dp)
//     {
//         if (m == 0)
//             return n;

//         if (n == 0)
//             return m;

//         if (dp[m][n] != -1) return dp[m][n];

//         if (s1.at(m-1) == s2.at(n-1))
//             return dp[m][n] = editDistance(s1, s2, m - 1, n - 1, dp);
        
//         return 
//             dp[m][n] = 
//             1 + 
//             min(
//             {
//                 editDistance(s1, s2, m, n-1, dp), 
//                 editDistance(s1, s2, m-1, n, dp), 
//                 editDistance(s1, s2, m-1, n-1, dp)
//             });
//     }
    int minDistance(string word1, string word2) {
        // memoized
        // int m = word1.size();
        // int n = word2.size();
        // vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
        // return editDistance(word1, word2, m, n, dp);
        
        // Dynamic Programming : 
        // 31ms 9.1MB
//         int m = word1.size();
//         int n = word2.size();
//         vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
//         for (int i = 0 ; i <= m ; i++) dp[i][0] = i;
//         for (int i = 0 ; i <= n ; i++) dp[0][i] = i;
//         for (int i = 1 ; i <= m ; i++) {
//             for (int j = 1; j <= n ; j++) {
//                 if (word1.at(i-1) == word2.at(j-1))
//                     dp[i][j] = dp[i-1][j-1];

//                 else 
//                     dp[i][j] = 1 + min(
//                         {
//                             dp[i][j-1],
//                             dp[i-1][j], 
//                             dp[i-1][j-1]
//                         });
//             }
//         } 
//         return dp[m][n];
        
        // Optimised
        // 13 ms 6.5MB
        int m = word1.size();
        int n = word2.size();
        vector<int> prev(n+1, 0), cur(n+1, 0);
        // for (int i = 0 ; i <= m ; i++) dp[i][0] = i;
        for (int i = 0 ; i <= n ; i++) prev[i] = i;
        for (int i = 1 ; i <= m ; i++) {
            cur[0]= i;
            for (int j = 1; j <= n ; j++) {
                if (word1.at(i-1) == word2.at(j-1))
                    cur[j] = prev[j-1];

                else 
                    cur[j] = 1 + min(
                        {
                            cur[j-1],
                            prev[j], 
                            prev[j-1]
                        });
            }
            prev = cur;
        } 
        return prev[n];
        
    }
};
