class Solution {
public:
    int maximumSum(vector<int>& nums) {

        int keep = nums[0];
        int deleteOne = 0;
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            deleteOne = max(deleteOne + nums[i], keep);

            keep = max(nums[i], keep + nums[i]);

            ans = max(ans, max(keep, deleteOne));
        }

        return ans;
    }
};