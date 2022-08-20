class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if (target <= startFuel) return 0;
//         int n = stations.size();
//         vector<long> ans(n + 1);
//         ans[0] = startFuel;
        
//         for (int i = 0 ; i < n ; i++) {
//             for (int j = i+1 ; j > 0 ; j--) {
//                 if (ans[j-1] >= stations[i][0])  
//                     ans[j] = max(ans[j], ans[j-1] + stations[i][1]);
//             }
//         }
        
//         for (int i = 0; i < ans.size() ; i++)
//             if (ans[i] >= target) return i;
//         return -1;
        
        int n = stations.size();
        int fuel = startFuel, cnt = 0, ans=0;
        priority_queue<int> pq;
        while (fuel < target) {
            while (cnt < n and fuel >= stations[cnt][0]) { 
               pq.push(stations[cnt][1]);
               cnt++;
            }
            if(pq.empty()) return -1;
            
            fuel = fuel + pq.top();
            pq.pop();
            
            ans++;
        }
        return ans;
    }
};
