class Solution {
public:
    int less_than_sum(vector<int>& nums, int goal){
        if(goal<0){
            return 0;
        }
        int currsum=0;
        int cnt=0;
        int low=0;
        for(int hg=0;hg<nums.size();hg++){
            currsum+=nums[hg];
            while(currsum>goal){
                currsum-=nums[low];
                low++;
            }cnt+=hg-low+1;    //track all posible subarray(between)
        }return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //  sum<=goal - sum<=goal-1  == sum==goal
        int ans=less_than_sum(nums, goal) - less_than_sum(nums, goal-1);
        return ans;
    }
};