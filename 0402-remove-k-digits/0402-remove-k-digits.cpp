class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(k==nums.size()){
            return "0";
        }
        stack<char>stk;
        string ans="";
        //we will start searching from left to right
        for(int i=0;i<nums.size();i++){
            while(!stk.empty() && k!=0 && stk.top()>nums[i]){   
                k--;
                stk.pop();
            }
            stk.push(nums[i]);  
        }

        while(k>0){
            stk.pop();
            k--;
        }

        while(!stk.empty()){
          ans += stk.top();
          stk.pop();
        }

        reverse(ans.begin(), ans.end());
        
        //detect starting 0ro
        int ind=0;
        for(ind=0;ind<ans.size();ind++){
            if(ans[ind]!='0'){
                break;
            }
        }
        
        
        ans=ans.substr(ind);
        if(ans==""){
            return "0";
        }return ans;
    }
};