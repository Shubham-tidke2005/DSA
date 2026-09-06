class Solution {
  public:
    string reverseWords(string &s) {
        // code here
        string ans="";
        int end=s.size()-1;
        int st;
        for(st=s.size()-1;st>=0;st--){
            if(s[st]=='.'){
                ans+=s.substr(st+1,end-st);
                if(end-st>0){
                    ans+='.';
                }
                end=st-1;
            }
        }
        
        ans+=s.substr(st+1,end-st);
        
        int ftd=0;
        while(ans[ftd]=='.'){
            ftd++;
        }
        
        int bkd=ans.size()-1;
        while(ans[bkd]=='.'){
            bkd--;
        }
        
        return ans.substr(ftd,bkd-ftd+1);
    }
};