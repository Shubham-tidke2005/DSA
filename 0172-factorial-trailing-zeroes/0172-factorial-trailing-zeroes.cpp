class Solution {
public:
    int trailingZeroes(int n) {
        //NORMAL APPROCH (CAL FACTORIAL CAN OVERFLOW INT-VARIABLE)
        int ans=0;
        while(n>0){
            n=n/5;
            ans+=n;
        }
        return ans;
    }
};