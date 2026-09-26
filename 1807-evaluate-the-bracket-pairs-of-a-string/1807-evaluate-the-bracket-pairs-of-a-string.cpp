class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>ump;
        string ans="";
        string currstr="";
        bool opb=false;

        for(int j=0;j<knowledge.size();j++){
            ump[knowledge[j][0]]=knowledge[j][1];
        }


        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                opb=true;
                continue;
            }
            else if(s[i]==')' ){
                if(ump.find(currstr)!=ump.end()){
                    ans+=ump[currstr];
                }else{
                    ans+='?';
                }
                currstr="";
                opb=false;
                continue;
            }else{
                if(opb){
                    currstr+=s[i];
                }else{
                    ans+=s[i];
                }

            }
        }return ans;
    }
};