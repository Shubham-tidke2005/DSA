class Solution {
public:
    int climbStairs(int n) {
        if(n<=1){
            return n;
        }
        
        int prv=1;   //n-1
        int prv2=0;  //n-2
        for(int i=2;i<=n;i++){
            int curr=prv+prv2;
            prv2=prv;
            prv=curr;
        }return prv+prv2;
    }
};