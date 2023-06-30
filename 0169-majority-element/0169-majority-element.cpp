class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto i:nums) mp[i]++;
        int ans ;
        for(auto i:mp) {
            if(i.second > n/2) {
                ans = i.first;
                break;
            }
        }
        return ans;
    }
};