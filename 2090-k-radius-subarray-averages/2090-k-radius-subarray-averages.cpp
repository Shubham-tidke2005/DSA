class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(),-1);
        if(nums.size()<=k*2){
            return ans;
        }

        long long currsum=0;
        long long winsize=k*2+1;
        for(int i=0;i<winsize;i++){
            currsum+=nums[i];
        }
        long long low=0;
        long long high=winsize-1;
        long long mid=(low+high)/2;
        ans[mid]=currsum/winsize;
        for(high=winsize;high<nums.size();high++){
            currsum+=nums[high];
            currsum-=nums[low];
            low++;
            mid=(low+high)/2;
            ans[mid]=currsum/winsize;
        }return ans;

    }
};