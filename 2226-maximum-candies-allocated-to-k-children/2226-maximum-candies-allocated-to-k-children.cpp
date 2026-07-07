class Solution {
public:
    //helper function
    bool canGive(vector<int>& nums,int mid, long long k){
        long long count=0;
        for(int i=0;i<nums.size();i++){
            long long cangive=(nums[i]/mid);
            if(cangive>0){
                count+=cangive;
            }

            if(count>=k){
                return true;
            }
        }return false;
    }
    int maximumCandies(vector<int>& nums, long long k) {
        int end=-1; //maxday
        int st=1;  //minday
        for(int i=0;i<nums.size();i++){
            end=max(end,nums[i]);
        }

        int maxcandy=0;

        while(st<=end){
            int mid = st + (end-st)/2;
            if(canGive(nums,mid,k)){
                maxcandy=max(mid,maxcandy);
                st=mid+1;
            }else{
                end=mid-1;
            }
        }return maxcandy;
    }
};