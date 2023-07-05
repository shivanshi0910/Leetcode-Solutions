class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0 , j=0;
        int n = nums.size();
        int ans = -1,fl=-1;
        while(j < n) {
            if(nums[j] == 1) j++;
            else if(fl == -1) {
                fl = j; 
                j++;
            }
            else {
                ans = max( ans , j-i-1);
                i = fl+1;
                fl = j;
                j++;
            }
        }
        ans = max(ans , j-i-1);
        return ans;
    }
};