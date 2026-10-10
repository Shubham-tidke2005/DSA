class Solution {
public:
    int manhattan_distance(vector<vector<int>>& points,int fst,int sec){
        return abs(points[fst][0]-points[sec][0]) + abs(points[fst][1]-points[sec][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();

        vector<bool> visited(n,false);
        //min heap <wt,point>
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        int mstCost=0;
        while(!pq.empty()){
            auto p=pq.top();
            int wt=p.first;
            int node=p.second;
            pq.pop();


            if(visited[node]){
                continue;
            }else{
                visited[node]=true;
                mstCost+=wt;
                for(int i=0;i<n;i++){
                    if(!visited[i]){
                        pq.push({manhattan_distance(points,node,i),i});
                    }
                }
            }
        }return mstCost;
    }
};