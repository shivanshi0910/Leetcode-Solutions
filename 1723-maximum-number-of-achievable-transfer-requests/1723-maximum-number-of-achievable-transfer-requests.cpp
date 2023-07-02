class Solution {
public:
    void solver(int n, vector<vector<int>>& requests , vector<int>& in , int i , int &ans , int st) {
        if(st == requests.size()) {
            for(int it=0 ; it<n ; it++) {
                if(in[it] != 0) return;
            }
            ans = max(ans , i);
            return;
        }
        in[requests[st][0]]--;
        in[requests[st][1]]++;
        solver(n , requests, in , i+1 , ans , st+1);
        in[requests[st][0]]++;
        in[requests[st][1]]--;
        solver(n , requests , in , i , ans , st+1);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int ans = 0;
        vector<int> in(n,0);
        solver(n , requests , in , 0 , ans , 0);
        return ans; 
    }
};