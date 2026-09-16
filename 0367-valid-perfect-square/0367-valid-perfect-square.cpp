class Solution {
public:
    bool isPerfectSquare(int num) {
        int st=1;
        int end=num;
        while(st<=end){
            long int mid=st+(end-st)/2;
            if(mid*mid==num){
                return true;
            }else if(mid*mid<num){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }return false;
    }
};