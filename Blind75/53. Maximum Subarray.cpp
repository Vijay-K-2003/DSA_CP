class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane Algorithm
        int max_here = INT_MIN;
        int max_end = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            max_end += nums[i];
            if(max_here < max_end) {
                max_here = max_end;
            } 
            if(max_end < 0) {
                max_end = 0;
            }
        }
        return max_here;
    }
};
