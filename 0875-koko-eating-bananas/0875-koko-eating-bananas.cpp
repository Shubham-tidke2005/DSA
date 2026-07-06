class Solution {
public:
    //helper function
    long long timereq(vector<int>& piles,long int speed){
        long long hour_req=0;
        for(int val:piles){
            hour_req+=int(val/speed);
            if(val%speed!=0){
                hour_req++;
            }
        }return hour_req;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxele=-1;
        for(int val:piles){
            maxele=max(val,maxele);
        }
        int st=1;
        long int end=maxele;
        long int min_ans=end;
        while(st<=end){
            long int mid=st+((end-st)/2);
            if(timereq(piles,mid)<=h){
                min_ans=min(min_ans,mid);
                end=mid-1;
            }else{
                st=mid+1;
            }
        }return min_ans;
    }
};


// if(nums[mid]==target){
//                 return mid;
//             }else if(nums[mid]>target){
//                 end=mid-1;
//             }else{
//                 st=mid+1;
//             }