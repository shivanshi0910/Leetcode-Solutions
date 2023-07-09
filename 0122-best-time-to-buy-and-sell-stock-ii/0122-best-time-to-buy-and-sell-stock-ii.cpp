class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int val = prices[0];
        int ans = 0;
        for(int i=1 ; i<n ; i++) {
            if(prices[i] > val) {
                ans += (prices[i]-val);
                val = prices[i];
            }
            else val = min(val , prices[i]);
        }
        return ans;
    }
};