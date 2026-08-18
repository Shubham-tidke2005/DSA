class Solution {
  public:
    vector<int> leaders(vector<int>& nums) {
        // code here
        int prevlarge=-1;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>=prevlarge){
                prevlarge=nums[i];
                ans.push_back(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};