class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1){
            return ;
        }

        k=k%nums.size();
        vector<int>bkele;
        int n=nums.size()-1;
        for(int i=0;i<k;i++){
            bkele.push_back(nums[n-i]);
        }

        int mvp=n;
        for(int i=n-k;i>=0;i--){
            swap(nums[mvp],nums[i]);
            mvp--;
        }

        
        for(auto val:bkele){
            nums[mvp]=val;
            mvp--;
        }
    }
};