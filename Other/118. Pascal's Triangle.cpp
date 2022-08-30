class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> solution(numRows);
        for (int i = 0; i < numRows; i++) {
            solution[i].resize(i + 1); // increase size by 1
            solution[i][0] = solution[i][i] = 1; // both 1st and last element one
  
            for (int j = 1; j < i; j++) 
                solution[i][j] = solution[i - 1][j - 1] + solution[i - 1][j];
        }
        return solution;
    }
};
