class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        for(int i=0 ; i<n ; i++) {
            if(nums[i] != 0) {
                nums[zero] = nums[i];
                zero++;
            }
        }
        for(int i=zero ; i<n ; i++) nums[i] = 0;
    }
};