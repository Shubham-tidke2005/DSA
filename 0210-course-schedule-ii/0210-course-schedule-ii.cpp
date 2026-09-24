class Solution {
public:

    bool checkCycle_dfs(int curr,vector<bool> &visited,vector<bool> &recPath, vector<vector<int>>& edges,vector<int> &ans){
        visited[curr]=true;
        recPath[curr]=true;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(u==curr){
                if(!visited[v]){
                    if(checkCycle_dfs(v,visited,recPath,edges,ans)){
                        return true;
                    }
                }else if(recPath[v]){
                    return true;
                }
            }
        }
        ans.push_back(curr);
        recPath[curr]=false;
        return false;
    }

    //problem is of cycle detection in directed graph
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        vector<bool>recPath(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(checkCycle_dfs(i,visited,recPath,edges,ans)){
                    return {};  //we can not finish all (Cycle)
                }
            }
        }
        
        return ans;
    }
     
};