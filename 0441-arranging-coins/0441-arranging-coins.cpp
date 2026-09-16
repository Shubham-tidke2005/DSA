class Solution {
public:
    int arrangeCoins(int n) {
    long int currcnplace=0;
      for(int i=0;i<n;i++){
        currcnplace+=i+1;
        if(currcnplace>n){
            return i;
        }
      }return 1;  
    }
};