class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxending=nums[0];
        int minending=nums[0];
        int maxproduct=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=nums[i];
            int v2=nums[i]*minending;
            int v3=nums[i]*maxending;
            minending=min(v1,min(v2,v3));
            maxending=max(v1,max(v2,v3));
            maxproduct=max(maxproduct,max(minending,maxending));
        }return maxproduct;
    }
};