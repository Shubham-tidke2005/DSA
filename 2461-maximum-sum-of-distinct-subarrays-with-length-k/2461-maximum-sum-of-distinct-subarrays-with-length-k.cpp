class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if(k==1){    //edge case
            int maxi=0;
            for(int i=0;i<nums.size();i++){
                maxi=max(maxi,nums[i]);
            }return maxi;
        }

        long long maxsum=0;   
        long long currsum=0;  //track currsum
        int low=0;
        unordered_set<int>st;
        st.insert(nums[low]);
        currsum = nums[0];           //push first element

        for(int high=1;high<nums.size();high++){
            currsum+=nums[high];
            if(st.find(nums[high])==st.end()){
                st.insert(nums[high]);
            }else{
                while(st.find(nums[high])!=st.end()){  //remove till duplicate is removed
                    currsum-=nums[low];
                    st.erase(nums[low]);
                    low++;
                }
                st.insert(nums[high]);
            }

            if(high-low+1==k){  //if window sized is match with k
                maxsum=max(currsum,maxsum);
                currsum-=nums[low];
                st.erase(nums[low]);  //remove low
                low++;
            }

        }return maxsum;
    }
};