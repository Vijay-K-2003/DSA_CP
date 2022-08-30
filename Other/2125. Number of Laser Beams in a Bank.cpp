class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int b_size = bank.size();
        if(b_size == 1) return 0;
        vector<int> count;
        for(int i = 0 ; i < b_size ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < bank[i].size() ; j++) {
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt != 0) count.push_back(cnt);
        }
        int c_size = count.size();
        if(c_size == 1 or c_size == 0) return false;
        int prod = 0;
        for(int i = 0 ; i < c_size-1 ; i++) {
            prod += count[i] * count[i+1];
        }
        return prod;
    }
};
