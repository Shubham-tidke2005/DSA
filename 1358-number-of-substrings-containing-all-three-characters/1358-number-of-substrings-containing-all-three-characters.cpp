class Solution {
public:
    int numberOfSubstrings(string s) {
        //char,freq
        unordered_map<char,int>ump;
        int ans=0;
        int low=0;
        for(int hg=0;hg<s.size();hg++){
            ump[s[hg]]++;
            while(ump.size()==3){
                ans+=s.size()-hg;    //size-curridx ---->if the solution is valid curr array then should be valid for next elements also before 
                ump[s[low]]--;
                if(ump[s[low]]==0){
                    ump.erase(s[low]);
                }
                low++;
            }
        }return ans;
    }
};