class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        set<int>strg;
        int st=0;
        int maxsum=0;
        int currsum=0;
        for(int i=0;i<nums.size();i++){
            currsum+=nums[i];
            if(strg.find(nums[i])==strg.end()){
                maxsum=max(maxsum,currsum);
            }else{
                while(strg.find(nums[i])!=strg.end()){
                    currsum-=nums[st];
                    strg.erase(nums[st]);
                    st++;
                }
            }strg.insert(nums[i]);
        }return maxsum;
    }
};