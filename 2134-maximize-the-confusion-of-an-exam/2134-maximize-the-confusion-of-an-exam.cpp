class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();
        int t = 0 , f = 0 , ans = 0;
        int i = 0 , j = 0;
        while(j < n) {
            if(answerKey[j] == 'T') t++;
            else f++;
            if(t<=k || f<=k) ans = max(ans , j-i+1);
            else {
                if(answerKey[i] == 'T') t--;
                else f--;
                i++;
            }
            j++;
        }
        return ans;
    }
};