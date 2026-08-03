class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(0 < (nums[i]-nums[i-1])){
                ans+=nums[i]-nums[i-1];
            }
        }return ans;
    }
};