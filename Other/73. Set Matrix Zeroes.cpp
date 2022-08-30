class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> r;
        vector<int> c;
        for (int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                // Traversing throught the whole matrix to identify
                // the Rows and Columns to be zero
                if (matrix[i][j] == 0) {
                    r.push_back(i); // Store Row numbers to be zero
                    c.push_back(j); // Store Column numbers to be zero
                }
            }
        }
        for (int i = 0 ; i < r.size() ; i++) {
            for(int j = 0 ; j < n ; j++) {
                // zero every marked row
                matrix[r[i]][j] = 0;
            }
        }
        for (int j = 0 ; j < c.size() ; j++) {
            for (int i = 0 ; i < m ; i++) {
                // zero every marked column
                matrix[i][c[j]] = 0;
            }
        }
    }
};
