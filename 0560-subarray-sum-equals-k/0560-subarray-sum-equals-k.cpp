class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int n = nums.size();
        int sum = 0 , cnt = 0;
        mp[sum] = 1;
        for(int i=0;i<n;i++) {
            sum += nums[i];
            int diff = sum-k;
            if(mp.find(diff) != mp.end()) {
                cnt += mp[diff];
            }
            mp[sum] ++;
        }
        return cnt;
    }
};