class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        queue<pair<int,int>> q;
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        int component = 0;
        for(int i=0; i<n; i++){
            if(visited[i]){
                continue;
            }
            component++;

            queue<int> q;
            q.push(i);
            visited[i] = true;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(auto &neighbor : adj[node]){
                    if(!visited[neighbor]){
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        } 
        return component;
    }
};
