class Solution {
public:
    int mySqrt(int x) {
        int st=0;
        int end=x;
        int nearest_sqr=-1;
        while(st<=end){
            long int mid=st+(end-st)/2;
            if(mid*mid==x){
                return mid;
            }else if(mid*mid>x){
                end=mid-1;
            }else{
                nearest_sqr=mid;
                st=mid+1;
            }
        }return nearest_sqr;
    }
};