class Solution {
public:
//tabulation
    // int rob(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<int>dp(n,0);
    //     dp[0]=nums[0];
    //     if(n>1){
    //         dp[1]=max(nums[0],nums[1]);
    //     }

    //     for(int i=2;i<n;i++){
    //         dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
    //     }
    //     return dp[n-1];
    // }

    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev_prev=nums[0];
        int curr=prev_prev;
        int prev;
        if(n>1){
            prev=max(nums[0],nums[1]);
            curr=prev;
        }
        
        for(int i=2;i<n;i++){
            curr=max(prev_prev+nums[i],prev);
            prev_prev=prev;
            prev=curr;
        }
        return curr;
    }
};