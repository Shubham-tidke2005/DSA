class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int pref=0;
        int totalsum=0;
        for(int i=0;i<nums.size();i++){
            totalsum+=nums[i];
        }

        //suffix=totalsum-preffix-currnumber

        for(int i=0;i<nums.size();i++){
            //prefix==suffix
            if(pref==(totalsum-pref-nums[i])){
                return i;
            }pref+=nums[i];
        }return -1;
    }
};