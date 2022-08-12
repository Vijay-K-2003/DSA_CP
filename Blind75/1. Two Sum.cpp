class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        unordered_map<int, int> mpp;
        for(int i = 0; i < nums.size(); i++) {
            if(mpp.find(target-nums[i]) != mpp.end()) {
                solution.push_back(mpp[target-nums[i]]);
                solution.push_back(i);
                return solution;
            }
            mpp[nums[i]] = i;
        }
        return solution;
    }
};
