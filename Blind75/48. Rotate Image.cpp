class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0 ; i < matrix.size() ; i++) {
            for(int j = i+1 ; j < matrix[0].size() ; j++) {
                swap(matrix[j][i], matrix[i][j]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};
