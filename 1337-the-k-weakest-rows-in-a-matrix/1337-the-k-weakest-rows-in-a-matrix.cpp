class Solution {
public:
    int countOnes(vector<int>& row){
        int st = 0;
        int end = row.size()-1;
        int ones = 0;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(row[mid] == 1){
                ones = mid+1;
                st = mid+1;
            }else{   
                end = mid-1;
            }
        }return ones;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        //count,row
        priority_queue<pair<int,int>>pq;   //Max heap
        for(int row=0;row<k;row++){
            int st=0;
            int end=mat[0].size()-1;
            pq.push({countOnes(mat[row]),row});
        }

        for(int row=k;row<mat.size();row++){
            int st=0;
            int end=mat[0].size()-1;
            int currones=countOnes(mat[row]);
            if(pq.top().first>currones){
                pq.pop();
                pq.push({currones,row});
            }
        }

        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;

    }
};