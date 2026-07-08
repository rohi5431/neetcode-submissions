class Solution {
public:
    void bfs(vector<vector<int>>& heights, queue<pair<int,int>> &q, vector<vector<bool>>& visited){
        int m = heights.size();
        int n = heights[0].size();
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto &d : dir){
                int nr = r + d.first;
                int nc = c + d.second;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && heights[nr][nc] >= heights[r][c]){
                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        queue<pair<int,int>> pacificQ,atlanticQ;

        for(int i=0; i<m; i++){
            pacific[i][0] = true;
            pacificQ.push({i,0});
        }

        for(int j=0; j<n; j++){
            pacific[0][j] = true;
            pacificQ.push({0,j});
        }

        for(int i=0; i<m; i++){
            atlantic[i][n-1] = true;
            atlanticQ.push({i,n-1});
        }

        for(int j=0; j<n; j++){
            atlantic[m-1][j] = true;
            atlanticQ.push({m-1,j});
        }

        bfs(heights,pacificQ,pacific);
        bfs(heights,atlanticQ,atlantic);


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
