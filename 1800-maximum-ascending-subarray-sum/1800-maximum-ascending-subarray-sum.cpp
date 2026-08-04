class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxsum=0;   //track which array has maximum sum
        int currsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){  //next element should be greater than add
                currsum+=nums[i];
            }else{                  // if smaller than than start from curr element
                maxsum=max(currsum,maxsum);
                currsum=nums[i];
            }
        }
        maxsum=max(currsum,maxsum); //check remaining val
        return maxsum;
    }
};