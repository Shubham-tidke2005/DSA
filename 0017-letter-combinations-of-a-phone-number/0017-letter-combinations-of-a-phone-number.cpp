class Solution {
public:
    vector<string> nums={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void helper(string digits,int ind,string curr_ans){
        if(ind==digits.size()){
            ans.push_back(curr_ans);
            return ;
        }

        int pos_in_nums=digits[ind] - '0';

        for(int i=0;i<nums[pos_in_nums].size();i++){
            curr_ans+=nums[pos_in_nums][i];
            helper(digits,ind+1,curr_ans);
            curr_ans=curr_ans.substr(0,curr_ans.size()-1);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        int ind=0;
        helper(digits,ind,"");
        return ans;
    }
};