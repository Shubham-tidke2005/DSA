class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {    
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        //moving zeros to end
        int sl=0;
        for(int fs=0;fs<nums.size();fs++){
            if(nums[sl]!=0){
                sl++;
            }else{
                if(nums[fs]!=0){
                    swap(nums[sl],nums[fs]);
                    sl++;
                }
            }
        }
        return nums;

    }
};