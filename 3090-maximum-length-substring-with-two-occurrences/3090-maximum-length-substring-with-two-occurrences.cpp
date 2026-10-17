class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int low=0;
        int maxlen=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;

            while (mp[s[i]] > 2) {
                mp[s[low]]--;
                low++;
            }

            maxlen = max(maxlen, i - low + 1);
        }return maxlen;
    }
};