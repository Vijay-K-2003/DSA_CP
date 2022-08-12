class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n , 1);
        int left = 1, right = 1;
        for(int i = 1 ; i < n ; i++) {
            answer[i] = answer[i]*left;
            answer[n-i-1] = answer[n-i-1]*right;
            left = left*nums[i];
            right = right*nums[n-i-1];
        }
        return answer;
    }
};
