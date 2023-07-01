class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        for(auto it:nums) mp[it]++;
        int i = 0;
        for(auto it:mp) {
            nums[i] = it.first;
            i++;
        }
        return mp.size();
    }
};