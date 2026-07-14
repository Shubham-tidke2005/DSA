class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>frq_alpha(128,0);
        for(int i=0;i<s.size();i++){
            frq_alpha[s[i]]++;
        }

        int long_len=0;

        
        int single_val=0;
        bool odd=false;
        for(auto val : frq_alpha){
            if(val%2==0){
                long_len+=val;
            }else{
                long_len += val - 1;
                odd=true;
            }
        }

        if(odd){
            long_len++;
        }

        return long_len;
    }
};