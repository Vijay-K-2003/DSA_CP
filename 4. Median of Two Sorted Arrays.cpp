class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // int i1 = 0, i2 = 0, i = 0;
        // vector<int> m(nums1.size() + nums2.size(), 0);
        // while(i1 < nums1.size() and i2 < nums2.size()) {
        //     if(nums1[i1] <= nums2[i2]) {
        //         m[i] = nums1[i1];
        //         i1++;
        //     } else {
        //         m[i] = nums2[i2];
        //         i2++;
        //     }
        //     i++;
        // }
        // while (i1 < nums1.size()) {
        //     m[i++] = nums1[i1++];
        // }
        // while (i2 < nums2.size()) {
        //     m[i++] = nums2[i2++];
        // }
        // for(auto a : m) {
        //     cout << a << " ";
        // }
        // cout << "\n";
        // int s = m.size();
        // if (s % 2 == 0) {
        //     return ((double)m[(s-1)/2] + (double)m[(s+1)/2])/2;
        // } else {
        //     return m[(s-1)/2];
        // }
        
        if(nums1.size() > nums2.size())
            swap(nums1, nums2);
        int n1 = nums1.size();
        int n2 = nums2.size();
        int l = 0;
        int r = n1;
        while(l <= r)
        {
            int i1 = (l + r)/2;
            int i2 = ((n1 + n2 + 1)/2 - (i1));
            int min1 = (i1==n1) ? INT_MAX : nums1[i1];
            int max1 = (i1==0) ? INT_MIN : nums1[i1-1];
            int min2 = (i2==n2) ? INT_MAX : nums2[i2];
            int max2 = (i2==0) ? INT_MIN : nums2[i2-1];
            if(max1 <= min2 && max2 <= min1)
            {
                if((n1 + n2)%2==0)
                    return ((double)max(max1, max2) + min(min1, min2)) / 2;
                else
                    return ((double) max(max1, max2));
            }
            else if(max1 > min2)
                r = i1-1;
            else
                l = i1+1;
        }
        return -1;
    }
};
