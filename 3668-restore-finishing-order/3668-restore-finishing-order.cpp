class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int>ust;
        for(int i=0;i<friends.size();i++){
            ust.insert(friends[i]);
        }
        int curr=0;
        for(int i=0;i<order.size();i++){
            if(ust.find(order[i])!=ust.end()){
                friends[curr]=order[i];
                curr++;
            }
        }

        return friends;
    }
};