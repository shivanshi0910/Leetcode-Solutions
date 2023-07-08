class Compi {
    public: 
        bool operator() (pair<int,int> a, pair<int,int> b) {
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
};
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;
        priority_queue<pair<int,int>,vector<pair<int,int>> , Compi> p;
        for(int i=0 ; i<nums.size() ; i++) mp[nums[i]]++;
        for(auto i:mp) p.push({i.second , i.first});
        vector<int>ans;
        while(p.size() > 0) {
            for(int i=0 ; i<p.top().first ; i++) ans.push_back(p.top().second);
            p.pop();
        }
        return ans; 
    }
};