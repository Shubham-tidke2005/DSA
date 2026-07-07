class Solution {
public:
    //helper function
    bool canMakeBou(vector<int>& nums, int guessDay, int k,int m){
        int count=0;
        for(int i=0;i<nums.size();i++){
            count++;
            if(nums[i]>guessDay){
                count=0;
            }

            if(count==k){
                m--;
                count=0;
            }
            if(m==0){
                return true;
            }

        }
        
        return false;
    }

    int minDays(vector<int>& nums, int m, int k) {
        int end=-1; //maxday
        int st=INT_MAX;  //minday
        for(int i=0;i<nums.size();i++){
            end=max(end,nums[i]);
            st=min(st,nums[i]);
        }

        int min_days=INT_MAX;

        while(st<=end){
            int mid=st+((end-st)/2);  //guess day
            if(canMakeBou(nums,mid,k,m)){
                min_days=min(min_days,mid);
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        if(min_days==INT_MAX){
            return -1;
        }
        return min_days;

    }
};