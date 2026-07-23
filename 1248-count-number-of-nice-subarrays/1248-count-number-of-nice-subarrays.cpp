class Solution {
public:
int less_than_k(vector<int>& nums, int k){
        if(k<0){
            return 0;
        }
        int currodds=0;
        int cnt=0;
        int low=0;
        for(int hg=0;hg<nums.size();hg++){
            if(nums[hg]%2!=0){
                currodds++;
            }
            
            while(currodds>k){
                if(nums[low]%2!=0){
                    currodds--;
                }
                low++;
            }cnt+=hg-low+1;    //track all posible subarray(between)
        }return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        //  odd<=k - odd<=k-1  == odd==k
        int ans=less_than_k(nums, k) - less_than_k(nums, k-1);
        return ans;
    }
};