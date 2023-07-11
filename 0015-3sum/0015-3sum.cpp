class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //base case
        if(n<3 || nums[0]>0) return ans;
        for(int i=0 ; i<n-1 ; i++) {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1 , k = n-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum < 0) j++;
                else if(sum > 0) k--;
                else {
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    int v1=nums[j] , v2=nums[k];
                    while(j<k && nums[j] == v1) j++;
                    while(j<k && nums[k] == v2) k--;
                }
            }
        }
        return ans;
    }
};