class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};
        int maxi = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = 0;

                    int cnt = 1;
                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();

                        for(auto &d : dir){
                            int nr = r + d.first;
                            int nc = c + d.second;

                            while(nr >=0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] != 0){
                                cnt++;
                                q.push({nr,nc});
                                grid[nr][nc] = 0;
                            }
                        }
                    }
                    maxi = max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
