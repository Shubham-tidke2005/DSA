class Solution {
public:
    int appendCharacters(string s, string t) {
        int sst=0;
        int tst=0;
        while(sst<s.size() && tst<s.size()){
            if(s[sst]==t[tst]){
                tst++;
            }sst++;
        }return t.size()-tst;
    }
};