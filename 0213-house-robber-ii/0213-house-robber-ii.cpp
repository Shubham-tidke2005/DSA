class Solution {
public:
    int rob_helper(vector<int>& nums,int st,int end){
        int prev_prev;
        if(nums.size()>st){
            prev_prev=nums[st];
        }else{
            return nums[0];
        }
        int curr=prev_prev;
        int prev;

        if(end>st+1){
            prev=max(nums[st],nums[st+1]);
            curr=prev;
        }else{
            return nums[st];
        }

        
        
        for(int i=st+2;i<end;i++){
            curr=max(prev_prev+nums[i],prev);
            prev_prev=prev;
            prev=curr;
        }
        return curr;
    }

    int rob(vector<int>& nums) {
        return max(rob_helper(nums,0,nums.size()-1),rob_helper(nums,1,nums.size()));
    }
};