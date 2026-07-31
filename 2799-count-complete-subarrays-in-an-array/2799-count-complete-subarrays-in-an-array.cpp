class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        //num,freq
        unordered_map<int,int>ump;
        //set for checking unique elements
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i])==st.end()){
                st.insert(nums[i]);
            }
        }

        int totalUni=st.size();
        int totalsubarray=0;
        int low=0;
        for(int hg=0;hg<nums.size();hg++){
            ump[nums[hg]]++;
            while(ump.size()==totalUni){
                totalsubarray+=nums.size()-hg;
                ump[nums[low]]--;
                if(ump[nums[low]]==0){
                    ump.erase(nums[low]);
                }
                low++;
            }
        }return totalsubarray;

    }
};