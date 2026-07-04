class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        //we can also use vector
        unordered_map<char,int>ump;

        //updating freq of each ele-->incresing
        for(int i=0;i<magazine.size();i++){
            ump[magazine[i]]++;
        }

        //redusing freq
        for(int i=0;i<ransomNote.size();i++){
            if(ump.find(ransomNote[i])!=ump.end()){
                ump[ransomNote[i]]--;
                if(ump[ransomNote[i]]==0){
                    ump.erase(ransomNote[i]);
                }
            }else{
                return false;
            }
        }return true;
    }
};