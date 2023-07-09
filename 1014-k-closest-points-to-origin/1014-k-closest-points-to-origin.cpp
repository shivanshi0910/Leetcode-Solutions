typedef std::pair<int,pair<int,int>> ppi;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        int n = points.size();
        priority_queue< ppi > pq;
        for(int i=0 ; i<n ; i++) {
            int disx = points[i][0]*points[i][0];
            int disy = points[i][1]*points[i][1];
            pq.push( {disx+disy , { points[i][0] , points[i][1] } } );
            if(pq.size() > k ) pq.pop();
        }
        while(pq.size() > 0) {
            ans.push_back( { pq.top().second.first , pq.top().second.second } );
            pq.pop();
        }
        return ans;
    }
};