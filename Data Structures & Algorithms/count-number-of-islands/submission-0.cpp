class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        vector<pair<int,int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1'){
                    cnt++;
 
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
 
                    while(!q.empty()){
                        auto [r,c] = q.front();
                        q.pop();

                        for(auto &d : dir){
                            int nr = r + d.first;
                            int nc = c + d.second;

                            while(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1'){
                                q.push({nr,nc});
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
