class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        //the biker is standing on zero altitude
        int curralti=0;
        int maxalti=0;  //track maximum altitude
        for(int i=0;i<gain.size();i++){
            curralti+=gain[i];
            maxalti=max(curralti,maxalti);
        }return maxalti;
    }
};