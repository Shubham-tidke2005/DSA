class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,0);
        left[0]=0;   // left prefix sum
        vector<int>right(n,0);
        right[n-1]=0;   // right prefix sum

        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<n-1;i++){
            leftsum+=nums[i];
            rightsum+=nums[n-1-i];
            left[i+1]=(leftsum);
            right[n-2-i]=(rightsum);
        }

        for(int i=0;i<nums.size();i++){
            nums[i]=abs(left[i]-right[i]);   //diff
        }return nums;
    }
};