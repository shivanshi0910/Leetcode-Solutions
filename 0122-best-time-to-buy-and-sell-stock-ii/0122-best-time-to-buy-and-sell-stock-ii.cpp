class Solution {
public:
    int help(int i, int buy , vector<int>& prices , vector<vector<long>>& dp) {
        int n = prices.size();
        if( i == n ) return 0;
        long long profit = 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy) {
            // profit = max(buy krna h , buy nhi krna)
            profit = max(-prices[i] + help(i+1,0,prices,dp) , help(i+1,1,prices,dp));
        }
        else {
            // profit = max(sell krna h , sell nhi krna)
            profit = max(prices[i] + help(i+1 , 1 ,prices , dp) , help(i+1 , 0 , prices,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n,vector<long>(2,-1));
        return help(0,1,prices,dp);
    }
};