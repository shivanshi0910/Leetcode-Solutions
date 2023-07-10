class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;
        int ans = INT_MIN;
        while(i < j) {
            ans = max( ans, (j-i)*min(height[i],height[j]) );
            height[i] > height[j] ? j--:i++;
        }
        return ans;
    }
};