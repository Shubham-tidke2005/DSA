class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n1st=0;
        int n2st=0;
        while(n1st<nums1.size() && n2st<nums2.size()){
            if(nums1[n1st]==nums2[n2st]){
                return nums1[n1st];
            }

            if(nums1[n1st]>nums2[n2st]){
                n2st++;
            }else{
                n1st++;
            }
        }return -1;
    }
};