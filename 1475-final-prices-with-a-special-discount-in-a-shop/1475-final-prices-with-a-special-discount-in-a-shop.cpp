class Solution {
public:
    vector<int> finalPrices(vector<int>& nums) {
        stack<int>stk;
        for(int i=nums.size()-1;i>=0;i--){
            int org=nums[i];
            while(!stk.empty() && stk.top()>nums[i]){
                stk.pop();
            }

            if(!stk.empty()){
                nums[i]=nums[i]-stk.top();
                stk.push(org);
                continue;
            }
            stk.push(org);
            nums[i]=stk.top();
        }return nums;
    }
};