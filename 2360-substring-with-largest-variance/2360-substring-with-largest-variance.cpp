class Solution {
public:
    int largestVariance(string s) {
        vector<int> cnt(26,0);
        for(char ch:s) cnt[ch-'a']++;
        int ans = 0;
        for(int i=0 ; i<26 ; i++) {
            for(int j=0 ; j<26 ; j++) {
                if(i == j || cnt[i] == 0 || cnt[j] == 0) continue;
                char maj = 'a'+i ,  min = 'a'+j;
                int majc = 0, minc = 0 , lc = 0 , rm = cnt[j];
                for(char ch:s) {
                    if(ch == maj) majc++;
                    if(ch == min) { minc++; rm--; }
                    lc = majc - minc;
                    if(minc > 0) ans = max(ans , lc);
                    if(lc < 0 && rm > 0) {
                        lc = 0;
                        majc = 0;
                        minc = 0;
                    } 
                }
            }
        }
        return ans;
    }
};