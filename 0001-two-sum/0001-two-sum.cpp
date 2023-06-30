class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            int ele = nums[i];
            if(mp.find(target-ele) != mp.end()) return {i,mp[target-ele]};
            mp[nums[i]]=i;
        }
        return {0,0};
    }
};