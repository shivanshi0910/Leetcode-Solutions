class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > p;
        map<int,int>mp;
        for(int i=0 ; i<nums.size() ; i++) mp[nums[i]]++;
        for(auto i:mp) {
            p.push({i.second , i.first});
            if(p.size() > k) p.pop();
        }
        vector<int>ans;
        while(p.size() > 0) {
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};