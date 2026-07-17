class Solution {
public:
    string reverseVowels(string s) {
        int st=0;
        int end=s.size()-1;
        while(st<end){
            char st_lower=tolower(s[st]);
            char end_lower=tolower(s[end]);
            if(st_lower!='a' && st_lower!='e' && st_lower!='i' && st_lower!='o' && st_lower!='u'){
                st++;
                continue;
            }if(end_lower!='a' && end_lower!='e' && end_lower!='i' && end_lower!='o' && end_lower!='u'){
                end--;
                continue;
            }

            char enddi=s[end];
            s[end]=s[st];
            s[st]=enddi;
            st++;
            end--;
        }return s;
    }
};