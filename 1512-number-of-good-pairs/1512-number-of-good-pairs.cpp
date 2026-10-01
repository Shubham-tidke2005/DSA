class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> ump;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(ump.find(nums[i])!=ump.end()){
                ans+=ump[nums[i]];
            }ump[nums[i]]++;
        }return ans;
    }
};