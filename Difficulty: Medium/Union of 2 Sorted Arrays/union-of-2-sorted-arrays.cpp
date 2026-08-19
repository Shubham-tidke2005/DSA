class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        int p1=0;
        int p2=0;
        int curr=0;
        vector<int>ans;
        if(a[0]<b[0]){
            ans.push_back(a[0]);
            p1++;
        }else{
            ans.push_back(b[0]);
            p2++;
        }
        
        while(p1<a.size() && p2<b.size()){
            if(a[p1]<b[p2]){
                if(ans[curr]!=a[p1]){
                    ans.push_back(a[p1]);
                    curr++;
                }p1++;
            }else if(a[p1]>b[p2]){
                if(ans[curr]!=b[p2]){
                    ans.push_back(b[p2]);
                    curr++;
                }p2++;
            }else{
                if(ans[curr]!=a[p1]){
                    ans.push_back(a[p1]);
                    curr++;
                }p1++;
                p2++;
            }
        }
        
        while(p1<a.size()){
            if(ans[curr]<a[p1]){
                ans.push_back(a[p1]);
                curr++;
            }p1++;
        }
        
        while(p2<b.size()){
            if(ans[curr]<b[p2]){
                ans.push_back(b[p2]);
                curr++;
            }p2++;
        }
        
        return ans;
    }
};