class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string finalword="";
        bool st1_turn=true;
        int st1=0;
        int st2=0;
        while(st1<word1.size() && st2<word2.size()){
            if(st1_turn){
                finalword+=word1[st1];
                st1++;
                st1_turn=false;
            }else{
                finalword+=word2[st2];
                st2++;
                st1_turn=true;
            }
        }

        while(st1<word1.size()){
            finalword+=word1[st1];
            st1++;
        }

        while(st2<word2.size()){
            finalword+=word2[st2];
            st2++;
        }return finalword;
    }
};