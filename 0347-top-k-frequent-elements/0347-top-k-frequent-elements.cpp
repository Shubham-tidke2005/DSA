class Solution {
public:
    //MIN HEAP
    struct cmp {
        bool operator()(pair<int,int> a, pair<int,int> b) {
            if(a.second!=b.second){
                return a.second>b.second;
            }
            return a.first > b.first;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>minhp;  //min heap
        unordered_map<int,int>ump; 
        for(int i=0;i<nums.size();i++){
           ump[nums[i]]++;
        }

        vector<int>ans;
        
        int curr=0;

        for(pair<int,int> val:ump){
            if(curr<k){
                minhp.push({val.first,val.second});
            }else{
                if(minhp.top().second<val.second){
                    minhp.pop();
                    minhp.push({val.first,val.second});
                }
            }curr++;
        }

        while(!minhp.empty()){
            ans.push_back(minhp.top().first);
            minhp.pop();
        }

        return ans;

    }
};


// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int>ump; 
//         for(int i=0;i<nums.size();i++){
//             if(ump.find(nums[i])==ump.end()){
//                 ump[nums[i]]=1;
//             }else{
//                 ump[nums[i]]=ump[nums[i]]+1;
//             }
//         }

//         vector<int>ans(k,0);
//         multimap<int,int>mp;
//         int ind=0;
//         for(pair<int,int> val:ump){
//             //cout<<val.first<<" "<<val.second<<endl;    //sorted order
//             mp.insert({val.second,val.first});
//             ind++;
//         }

//         int curr=0;
//         int i=0;
//         for(pair<int,int> val:mp){
//             if(ind-k<=curr){
//                 ans[i]=val.second;
//                 i++;
//             }curr++;
//         }
//         return ans;

//     }
// };