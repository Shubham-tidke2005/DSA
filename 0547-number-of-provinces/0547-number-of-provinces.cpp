class Solution {
public:
    void dfs(int st,vector<vector<int>> &isConnected,int n,vector<bool> &visited){
        visited[st]=true;
        for(int j=0;j<n;j++){
            if(!visited[j] && isConnected[st][j]==1){
                dfs(j,isConnected,n,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected[0].size();
        vector<bool>visited(n,false);
        int cnt_province=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt_province++;
                dfs(i,isConnected,n,visited);
            }
        }return cnt_province;

    }
};