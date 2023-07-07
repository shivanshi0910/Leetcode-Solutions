class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        set<int>s1,s2;
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(matrix[i][j] == 0) {
                    s1.insert(i);
                    s2.insert(j);
                }
            }
        }
        for(auto it:s1) {
            for(int i=0 ; i<m ; i++) {
                matrix[it][i] = 0;
            }
        }
        for(auto it:s2) {
            for(int i=0 ; i<n ; i++) {
                matrix[i][it] = 0;
            }
        }
    }
};