class Solution {
public:
    vector<int> decrypt(vector<int>& nums, int k) {
        vector<int>ans(nums.size(),0);
        int n=nums.size();
        if(k==0){
            return ans;
        }

        
        if(0<k){
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=nums[i%n];
            }
            int high=k;
            for(int low=0;low<n;low++){
                sum+=nums[high%n];
                high++;
                sum-=nums[low];
                ans[low]=sum;                        
            }
        }else{
            k = -k;
            int sum=0;
            for(int i=0;i<k;i++){
                sum+=nums[(n-1-i)%n];
            }
            int low=n-1-k;
            int pos=low;
            for(int high=n-1;high>=0;high--){
                
                sum+=nums[(low+n)%n];
                low--;
                sum-=nums[high];
                ans[high]=sum;         
            }
        }
        return ans;
    }
};