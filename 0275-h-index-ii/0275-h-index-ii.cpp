class Solution {
public:
    int hIndex(vector<int>& nums) {
        int st=0;
        int end=nums.size()-1;
        int h_ind=-1;
        while(st<=end){
            int mid=st+((end-st)/2);
            if((nums.size()-mid)==nums[mid]){
                return nums[mid];
            }else if((nums.size()-mid)>nums[mid]){
                h_ind=mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }return (nums.size()-h_ind-1);
    }
};