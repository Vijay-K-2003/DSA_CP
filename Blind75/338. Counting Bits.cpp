class Solution {
public:
    vector<int> countBits(int n) {
        if (n == 0) {
            return {0};
        } 
        vector<int> hist(n+1, 0);
        hist[0] = 0;
        hist[1] = 1;
        for(int i = 2 ; i <= n ; i++) {
            hist[i] = i%2 + hist[i>>1];
        }
        return hist;
    }
};
