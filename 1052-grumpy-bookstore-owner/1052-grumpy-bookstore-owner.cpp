class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        //by redefining the problem we just need to find unsatisfied coustomer
        int currunsatisfied=0;
        int maxunsatisfied=0;
        int satisfied=0;
        int low;

        //finding first unsatisfied
        for(low=0;low<minutes;low++){
            if(grumpy[low]==1){
                currunsatisfied+=customers[low];
            }else{
                satisfied+=customers[low];   //counting satisfied ones
            }
        }maxunsatisfied=currunsatisfied;

        low=0;
        //finding max unsatisfied
        for(int hg=minutes;hg<grumpy.size();hg++){
            if(grumpy[low]==1){
                currunsatisfied-=customers[low];   
            }low++;

            if(grumpy[hg]==1){
                currunsatisfied+=customers[hg];   
            }else{
                satisfied+=customers[hg];
            }
            maxunsatisfied=max(maxunsatisfied,currunsatisfied);
        }
        return maxunsatisfied+satisfied;  //max consecutive unsatisfied+total satisfied
    }
};