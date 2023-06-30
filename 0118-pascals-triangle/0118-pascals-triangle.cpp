class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        vector<int> temp = ans.back();
        for(int i = 2 ; i <= numRows ; i++) {
            vector<int>val;
            val.push_back(1);
            for(int i=0 ; i<temp.size()-1 ; i++) {
                val.push_back(temp[i]+temp[i+1]);
            }
            val.push_back(1);
            ans.push_back(val); 
            temp = val;
        }
        return ans;
    }
};