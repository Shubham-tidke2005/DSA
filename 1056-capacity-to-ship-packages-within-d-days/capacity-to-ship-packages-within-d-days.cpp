class Solution {
public:
    //helper function
    int dayReq(vector<int>& nums, int guess_cap){
        int curr_cap=0;
        int day_req=0;
        for(int i=0;i<nums.size();i++){
            if(curr_cap+nums[i]>guess_cap){
                day_req++;
                curr_cap=0;
            }curr_cap+=nums[i];
        }
        if(curr_cap<=guess_cap){
            day_req++;
        }
        return day_req;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int end=0; //maxday
        int st=-1;  //minday
        for(int i=0;i<nums.size();i++){
            end+=nums[i];
            st=max(nums[i],st);
        }

        int mincap=INT_MAX;

        while(st<=end){
            int mid = st + (end-st)/2;   //guess pakages the ship can transform
            if(dayReq(nums,mid)<=days){
                mincap=min(mid,mincap);
                end=mid-1;
            }else{
                st=mid+1;
            }
        }return mincap;
    }
};