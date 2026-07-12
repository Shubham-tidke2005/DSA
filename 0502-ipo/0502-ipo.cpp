class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vec;
        for(int i=0;i<profits.size();i++){
            vec.push_back({capital[i],profits[i]});
        }

        sort(vec.begin(),vec.end());

        int idx=0;
        priority_queue<int>pq;  //maxheap
        while(k--){
            while(idx<profits.size()){
                if(vec[idx].first>w){
                    break;
                }pq.push(vec[idx].second);
                idx++;
            }
            if(pq.empty()){
                return w;
            }else{
                w=w+pq.top();
                pq.pop();
            }
        }return w;

    }
};