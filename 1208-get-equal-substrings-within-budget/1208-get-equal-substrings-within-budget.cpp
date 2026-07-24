class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int low=0;
        int maxlen=0;
        int currcost=0;
        for(int high=0;high<s.size();high++){
            currcost+=abs(s[high]-t[high]);  //diff of asci val
            while(currcost>maxCost){
                currcost-=abs(s[low]-t[low]);  //removing elements from st
                low++;
            }
            maxlen=max(maxlen,high-low+1);
        }return maxlen;
    }
};