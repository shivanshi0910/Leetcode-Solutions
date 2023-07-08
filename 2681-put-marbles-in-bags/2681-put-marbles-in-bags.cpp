class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<int> maxh;
        priority_queue<int,vector<int>,greater<int>> minh;
        for(int i=0 ; i<weights.size()-1 ; i++) {
            maxh.push(weights[i]+weights[i+1]);
            if(maxh.size() == k) maxh.pop();
            minh.push(weights[i]+weights[i+1]);
            if(minh.size() == k) minh.pop();
        }
        long long ans = 0;
        while(minh.size() > 0) {
            ans += minh.top() - maxh.top();
            minh.pop();
            maxh.pop();
        }
        return ans;
    }
};