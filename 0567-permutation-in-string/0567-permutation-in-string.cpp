
class Solution {
public:
    bool isequal(int arr1[],int arr2[]){
        for(int i=0;i<26;i++){
            if(arr1[i]!=arr2[i]){
                return false;
            }
        }return true;
    }
    bool checkInclusion(string s1, string s2){
       int freq[26]={0};
       for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;  //s[i]-'a'---->index
       }
       for(int i=s1.length()-1;i<s2.length();i++){
            int winend=i;
            int winstart= winend-s1.length()+1;
            int winfreq[26]={0};
            while(winstart<=winend){
                winfreq[s2[winstart]-'a']++;
                winstart++;
            }if(isequal(freq,winfreq)){
                return true;
            }
       }
       return false;
    }
};