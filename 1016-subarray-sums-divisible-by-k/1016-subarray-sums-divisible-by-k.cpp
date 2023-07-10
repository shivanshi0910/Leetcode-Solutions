class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int n = nums.size();
        int prevsum = 0;
        int ans = 0;
        mp[0]=1;
        for(int i=0 ; i<n ; i++) {
            prevsum = (prevsum + nums[i] % k + k ) % k;
            ans += mp[prevsum];
            mp[prevsum]++;
        }
        return ans;
    }
};