class Solution {
public:
    int maxProfit(vector<int>& nums) {
        // stack<int>stk;
        int maxsell_right=0;
        int maxprof=0;
        for(int hg=nums.size()-1;hg>=0;hg--){
            // while(!stk.empty() && nums[stk.top()]<=nums[hg]){
            //     stk.pop();
            // }
            maxsell_right=max(nums[hg],maxsell_right);
            maxprof=max(maxprof,maxsell_right-nums[hg]);
            // stk.push(hg);

        }return maxprof;
    }
};