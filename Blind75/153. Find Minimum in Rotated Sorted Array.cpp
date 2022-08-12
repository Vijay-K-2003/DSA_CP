class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int res = nums[0];
        while(left <= right) {
            if(nums[left] <= nums[right]) {
                res = min(res, nums[left]);
            }
            int mid = (left + right)/2;
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[left]) {
                //search right
                left = mid+1;
            } else {
                //search left
                right = mid-1;
            }
        }
        return res;
    }
};
