class Solution {
public:
    int maxArea(vector<int>& height) {
        // Brute Force O(n^2)
        // int res = 0;
        // for (int i = 0 ; i < height.size() ; i++) {
        //     for (int j = i+1 ; j < height.size() ; j++) {
        //         res = max(res, min(height[i], height[j]) * (j-i));
        //     }
        // }
        // return res;
        int res = 0;
        int l = 0, r = height.size()-1;
        while (l < r) {
            res = max(res, (r-l)*min(height[l], height[r]));
            if(height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
