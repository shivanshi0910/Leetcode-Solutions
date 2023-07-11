class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // concept is like circular sliding window
        // 1 2 3 _ _ _ _ = 6
        // 1 2 _ _ _ _ 1 = 4
        // 1 _ _ _ _ 6 1 = 8
        // _ _ _ _ 5 6 1 = 12
        int n = cardPoints.size();
        int ans = 0;
        for(int i=0 ; i<k ; i++) ans += cardPoints[i]; // 1 2 3
        int temp = ans;
        for(int i=k-1 ; i>=0 ; i--) {
            temp -= cardPoints[i];
            temp += cardPoints[n-k+i];
            ans = max(ans , temp); 
        }
        return ans;
    }
};