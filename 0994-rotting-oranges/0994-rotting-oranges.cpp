class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>que;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }

        while(!que.empty()){
            int i=que.front().first.first;
            int j=que.front().first.second;
            int time=que.front().second;
            minute=max(minute,time);
            que.pop();

            if(i-1>=0 && !visited[i-1][j] && grid[i-1][j]==1){
                que.push({{i-1,j},time+1});
                visited[i-1][j]=true;
            }

            if(j-1>=0 && !visited[i][j-1] && grid[i][j-1]==1){
                que.push({{i,j-1},time+1});
                visited[i][j-1]=true;
            }

            if(i+1<n && !visited[i+1][j] && grid[i+1][j]==1){
                que.push({{i+1,j},time+1});
                visited[i+1][j]=true;
            }

            if(j+1<m && !visited[i][j+1] && grid[i][j+1]==1){
                que.push({{i,j+1},time+1});
                visited[i][j+1]=true;
            }

        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    return -1;
                }
            }
        }return minute;

    }
};