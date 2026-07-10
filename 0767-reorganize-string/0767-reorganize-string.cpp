class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>ump;
        for(int i=0;i<s.size();i++){
            ump[s[i]]++;
        }

        priority_queue<pair<int,char>>pq;  //Maxheap
        for(auto val:ump){
            pq.push({val.second,val.first});
        }

        int st=0;
        string ans="";
        while(!pq.empty()){
            pair<int,char>val=pq.top();
            pq.pop();
            if(st==0 || ans[st-1]!=val.second){
                ans+=val.second;
                val.first--;
                if(val.first>0){
                    pq.push({val});
                }
            }else{
                //pop one more element
                if(pq.empty()){
                    return "";
                }
                pair<int,char>val2=pq.top();
                pq.pop();
                ans+=val2.second;
                val2.first--;
                if(val.first > 0)
                    pq.push(val);

                if(val2.first > 0)
                    pq.push(val2);
            }st++;
        }return ans;
    }
};