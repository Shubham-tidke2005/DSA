class Solution {
public:
    void dfs(int i,int j,vector<vector<bool>> &visited,vector<vector<char>> &grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0' || visited[i][j]){
            return ;
        }

        visited[i][j]=true;
        dfs(i+1,j,visited,grid);
        dfs(i-1,j,visited,grid);
        dfs(i,j-1,visited,grid);
        dfs(i,j+1,visited,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count_ilnd=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count_ilnd++;
                    dfs(i,j,visited,grid);
                }
            }
        }return count_ilnd;
    }
};