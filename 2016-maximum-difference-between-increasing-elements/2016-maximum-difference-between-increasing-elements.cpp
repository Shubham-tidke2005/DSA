class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxdiff=-1;
        int mini=nums[0];
        for(int i=1;i<nums.size();i++){
            mini=min(nums[i],mini);  //track minimum distance till curr n0.
            if(mini<nums[i]){
                maxdiff=max(nums[i]-mini,maxdiff);
            }
        }
        return maxdiff;
    }
};