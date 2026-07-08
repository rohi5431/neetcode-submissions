class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
         
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            for(auto &d : dir){
                int nr = r + d.first;
                int nc = c + d.second;

                while(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == INT_MAX){
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr,nc});
                }
            }
        }
    }
};
