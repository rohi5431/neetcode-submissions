class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        int m = prerequisites.size();
        int n = prerequisites[0].size();

        for(auto &p : prerequisites){
            int u = p[0];
            int v = p[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
               q.push(i);
            }
        }
        int visited = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            visited++;
            for(auto neighbor : adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }
        return visited == numCourses;
    }
};
