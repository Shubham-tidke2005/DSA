class Solution {
public:
    int leastInterval(vector<char>& nums, int n) {
        //map
        unordered_map<char,int>ump;
        //maxheap
        priority_queue<int>pq;
        for(char val:nums){
            ump[val]++;
        }

        for(auto val:ump){
            pq.push(val.second);
        }
        

        int intervals=0;
        bool last=false;
        while(!pq.empty()){
            vector<int>temp;
            if(pq.top()==1){
                last=true;
            }
            for(int i=0;i<=n;i++){
                if(pq.empty() && !last){
                    intervals++;
                    
                }else{
                    if(!pq.empty()){
                        temp.push_back(pq.top());
                        pq.pop();
                        intervals++;
                    }
                }
            }

            for(int val:temp){
                if(val-1>0){
                    pq.push(val-1);
                }
            }
        }return intervals;
    }
};