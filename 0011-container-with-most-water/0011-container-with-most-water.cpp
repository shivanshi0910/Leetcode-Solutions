class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;
        int ans = INT_MIN;
        while(i < j) {
            int minh = min(height[i] , height[j]);
            ans = max(ans, (j-i)*minh);
            while(height[i] <= minh && i<j) i++;
            while(height[j] <= minh && i<j) j--;
        }
        return ans;
    }
};