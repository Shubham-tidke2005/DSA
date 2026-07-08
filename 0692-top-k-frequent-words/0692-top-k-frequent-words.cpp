class Solution {
public:
    struct cmp{
        bool operator()(pair<string,int> a,pair<string,int> b){
            if(a.second == b.second){
                 return a.first < b.first;   // lexicographically smaller has higher priority
            }
            return a.second > b.second;     // smaller frequency stays on top
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>ump;
        for(auto val:words){
            ump[val]++;
        }

        vector<string>ans;
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp>mpq;  //mean heap
        int cnt=0;
        for(pair<string,int> val:ump){
            if(cnt<k){
                mpq.push({val});
            }else{
                if(val.second>mpq.top().second || (val.second == mpq.top().second && val.first < mpq.top().first)){
                    mpq.pop();
                    mpq.push({val});
                }
            }
            cnt++;
        }

        while(!mpq.empty()){
            ans.push_back(mpq.top().first);
            mpq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};