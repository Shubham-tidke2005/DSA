class Solution {
public:
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>>pq;   //Maxheap
        for(int i=0;i<k;i++){
            int dist = points[i][0]*points[i][0] +points[i][1]*points[i][1];
            pq.push({dist,i});
        }

        for(int i=k;i<points.size();i++){
            int dist = points[i][0]*points[i][0] +points[i][1]*points[i][1];
            if((pq.top().first )  > dist){
                pq.pop();
                pq.push({dist,i});
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back({points[pq.top().second]});
            pq.pop();
        }return ans;
    }
};