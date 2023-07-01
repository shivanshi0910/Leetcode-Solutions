class Solution {
public:
    void solve(vector<int>&cookies , int k , int &ans , vector<int>&v , int i) {
        if(i == cookies.size()) {
            int val = INT_MIN;
            for(int it=0 ; it<k ; it++) val = max(val , v[it]);
            ans = min(ans , val);
            return ;
        }
        for(int it=0 ; it<k ; it++) {
            v[it] += cookies[i];
            solve(cookies,k,ans,v,i+1);
            v[it] -= cookies[i];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int>v(k,0);
        solve(cookies,k,ans,v,0);
        return ans;
    }
};