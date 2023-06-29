class Solution {
public: 
    bool isSafe(int node,int col, vector<int> &flower,map<int,vector<int>> &adj) {
        for(auto v : adj[node]){
            if(flower[v-1]==col) return false;
        }
        return true;
    }
    bool solve(int node,int n, vector<int> &flower,map<int,vector<int>> &adj ){
        if(node == n+1) return true;
        for(int col=1;col<=4;col++){
            if(isSafe(node,col,flower,adj)){
                flower[node-1]=col;
                if(solve(node+1,n,flower, adj)==true) return true;
                flower[node-1]=0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        map<int,vector<int>> adj;
        for(auto it:paths) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> flower(n,0);
        solve(1,n,flower,adj);
        return flower;
    }
};