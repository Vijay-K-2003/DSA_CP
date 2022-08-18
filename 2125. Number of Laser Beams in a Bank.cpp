class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        if(bank.size() == 1) return 0;
        vector<int> count;
        for(int i = 0 ; i < bank.size() ; i++) {
            int cnt = 0;
            for(int j = 0 ; j < bank[i].size() ; j++) {
                if(bank[i][j] == '1') cnt++;
            }
            if(cnt != 0) count.push_back(cnt);
        }
        if(count.size() == 1 or count.size() == 0) return false;
        int prod = 0;
        for(int i = 0 ; i < count.size()-1 ; i++) {
            prod += count[i] * count[i+1];
        }
        return prod;
    }
};
