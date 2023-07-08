class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=0 , n=nums.size();
        int prev = -101;
        for(int i=0 ; i<n ; i++) {
            if(nums[i] == prev) continue;
            else {
                nums[j++] = nums[i];
                prev = nums[i];
            }
        }
        return j;
    }
};