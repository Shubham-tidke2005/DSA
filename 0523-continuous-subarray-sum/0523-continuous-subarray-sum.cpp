class Solution {
public:

    //EXAMPLE
    //nums = [23,2,4,6,7], k = 6
    // UMP=>{5:0, 1:1, 5:2(CONDITION)}
    //SUM = IND1 AND IND2 == MULTIPLE OF 6

    bool checkSubarraySum(vector<int>& nums, int k) {
        //remainder , idex
        unordered_map<int,int>ump;
        ump[nums[0]%k]=0;        //rem of first index , starting index
        int currsum=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==0 && nums[i]==0){    //if two conicative 0 then it multiple of k given
                return true;
            }

            currsum+=nums[i];
            if(currsum%k==0){
                return true;
            }
            int currem=currsum%k;   //calculate remender every time
            if(ump.find(currem)!=ump.end()){   //if rem is present in man cal distance
                if(i-ump[currem]>=2){  //atleast 2 element
                    return true;
                }
            }else{
                ump[currem]=i;   //if not exits then add rem,ind
            }
        }return false;
    }
};