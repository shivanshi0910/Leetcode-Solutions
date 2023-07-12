class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> rev(V);
        vector<int> outdegree(V), safe(V), ans;
        queue<int> q;
        for (int i = 0; i < V; i++) {
            for (int v : graph[i]) {
                rev[v].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = 1;
            for (int v : rev[node]) {
                outdegree[v]--;
                if (outdegree[v] == 0) q.push(v);
            }
        }
        for (int i = 0; i < V; ++i) {
            if (safe[i]) ans.push_back(i);
        }
        return ans;
    }
};