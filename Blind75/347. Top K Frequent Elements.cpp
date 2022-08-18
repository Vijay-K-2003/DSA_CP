class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }
        
        // create bucket of size n+1
        // this will contain the number of nums with same count
        vector<vector<int>> buckets(n+1);
        for(auto it = mp.begin() ; it != mp.end() ; it ++) {
            buckets[it->second].push_back(it->first);
        }
        vector<int> sol;
        for(int i = n ; i >= 0 ; i--) {
            if (sol.size() >= k) {
                break;
            }
            if(!buckets[i].empty()) {
                sol.insert(sol.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        return sol;
    }
};
