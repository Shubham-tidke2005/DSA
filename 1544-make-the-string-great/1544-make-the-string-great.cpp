class Solution {
public:
    string makeGood(string s) {
        stack<char>stk;
        for(int i = 0; i < s.size(); i++) {
            if(!stk.empty() && tolower(stk.top()) == tolower(s[i]) && stk.top() != s[i]) {
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }

        s="";
        while(!stk.empty()){
            s=stk.top()+s;
            stk.pop();
        }return s;
    }
};