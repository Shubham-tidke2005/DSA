class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char small_gre='-';
        int st=0;
        int end=letters.size()-1;
        while(st<=end){
            long int mid=st+(end-st)/2;
            if(int(letters[mid]-target) > 0){
                small_gre=letters[mid];
                end=mid-1;
            }else{
                st=mid+1;
            }
        }

        if(small_gre != '-'){
            return small_gre;
        }return letters[0];
    }
};