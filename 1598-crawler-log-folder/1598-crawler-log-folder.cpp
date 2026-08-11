class Solution {
public:
    int minOperations(vector<string>& nums) {
        int sz=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]=="./"){
                continue;
            }

            if(nums[i]=="../"){
                if(sz!=0){
                    sz--;
                }
            }else{
                sz++;
            }
        }return sz;
    }
};