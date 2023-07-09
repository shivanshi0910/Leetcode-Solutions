class Solution {
public:
    /*int help(int i, int buy , vector<int>& prices , vector<vector<long>>& dp) {
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
    }*/
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> dp(n+1,vector<long>(2,0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for(int i=n-1 ; i>=0 ; i--) {
            for(int b=0 ; b<=1 ; b++) {
                long long profit=  0;
                if(b) {
                    // profit = max(buy krna h , buy nhi krna)
                    profit = max(-prices[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else {
                    // profit = max(sell krna h , sell nhi krna)
                    profit = max(prices[i] + dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][b] = profit;
            }
        }
        return dp[0][1];
    }
};