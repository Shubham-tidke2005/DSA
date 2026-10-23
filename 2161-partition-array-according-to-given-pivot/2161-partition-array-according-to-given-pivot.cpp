class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>ans;
        int eql=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
            }if(nums[i]==pivot){
                eql++;
            }
        }

        for(int i=1;i<=eql;i++){
            ans.push_back(pivot);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
            }
        }return ans;
    }
};