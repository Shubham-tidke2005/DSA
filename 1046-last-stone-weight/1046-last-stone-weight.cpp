class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        //use maxheap
        priority_queue<int>pq;  
        for(int val:stones){
            pq.push(val);
        }

        int ans=0;
        while(!pq.empty()){
            int val1=pq.top();
            pq.pop();
            if(!pq.empty()){
                int val2=pq.top();
                pq.pop();

                if(abs(val1-val2)>0){
                    pq.push(abs(val1-val2));
                }

            }else{
                ans=val1;
                break;
            }
        }return ans;
        
    }
};