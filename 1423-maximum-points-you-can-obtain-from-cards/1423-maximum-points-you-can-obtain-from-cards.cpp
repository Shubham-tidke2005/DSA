class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        //we can pick elements form start and end continuosly
        int n=nums.size();
        int currsum=0;
        int maxsum=0;

        //first k as maxsum
        for(int i=0;i<k;i++){
            currsum+=nums[i];
        }maxsum=max(currsum,maxsum);

        int rst=n-1;
        for(int lst=k-1;lst>=0;lst--){   //move left from k position
            currsum+=nums[rst];  //add element of end
            rst--;
            currsum-=nums[lst];  //remove element
            maxsum=max(currsum,maxsum);
        }return maxsum;
    }
};