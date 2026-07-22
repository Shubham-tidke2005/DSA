class Solution {
public:
    //fixed size sliding window
    int maxVowels(string s, int k) {
        int maxvl=0;  //max substring vowel 
        int currvl=0;
        int st=0;

        //find first k vowel
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                maxvl++;
                currvl++;
            }
        }

        for(int hg=k;hg<s.size();hg++){
            //remove first
            if(s[st]=='a' || s[st]=='e' || s[st]=='i' || s[st]=='o' || s[st]=='u'){
                currvl--;
                st++;
            }else{
                st++;
            }
            
            //add next
            if(s[hg]=='a' || s[hg]=='e' || s[hg]=='i' || s[hg]=='o' || s[hg]=='u'){
                currvl++;
                maxvl=max(maxvl,currvl);
            }
        }
        return maxvl;
    }
};