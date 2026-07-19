class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_st=0;
        int t_st=0;
        while(s_st<s.size() && t_st<t.size()){
            if(s[s_st]==t[t_st]){
                s_st++;
                //t_st++;  //we need subsequence  so moving forward is not option
            }
            t_st++;
        }

        if(s_st<s.size()){
            return false;
        }return true;
    }
};