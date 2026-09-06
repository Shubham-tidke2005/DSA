class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        //number and freq,position
        unordered_map<int,pair<int,int>>ump;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap; 
        
        for(int i=0;i<arr.size();i++){
            if(ump.find(arr[i])==ump.end()){
                ump[arr[i]].first++;
                ump[arr[i]].second=i;
                
            }else{
                ump[arr[i]].first++;
            }
            
        }
        
        for(auto &val:ump){
            if(minHeap.size()<k){
                minHeap.push({val.second.first,val.first});
                continue;
            }else{
                if(minHeap.top().first==val.second.first){
                    if(minHeap.top().second>val.first){
                        continue;
                    }else{
                        minHeap.pop();
                        minHeap.push({val.second.first,val.first});
                    }continue;
                }
                if(minHeap.top().first < val.second.first){
                    minHeap.pop();
                    minHeap.push({val.second.first,val.first});
                }
            }
        }
        
        vector<int>ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
