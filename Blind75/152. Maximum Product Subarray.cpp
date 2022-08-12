class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            res = max(res, nums[i]);
        } 
        int currMax = 1, currMin = 1;
        for(int i = 0 ; i < n ; i++) {
            int temp = nums[i] * currMax;
            currMax = max({nums[i] * currMax, nums[i] * currMin, nums[i]});
            currMin = min({temp, nums[i] * currMin, nums[i]});
            res = max({currMax,currMin,res});
        }
        return res;
    }
};
