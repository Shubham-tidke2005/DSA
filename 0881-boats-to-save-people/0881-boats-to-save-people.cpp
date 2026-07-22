class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        //we can only transfer 2 people at time
        sort(people.begin(),people.end());
        int boat=0;
        int st=0;
        int end=people.size()-1;
        while(st<=end){
            if(people[st]+people[end]<=limit){
                st++;
                end--;
                
            }else{
                end--;
            }boat++;
        }
        return boat;
    }
};