class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int currow=0;
        int curcol=matrix[0].size()-1;
        while(currow<matrix.size() && curcol>=0){
            if(matrix[currow][curcol]==target){
                return true;
            }else if(target<matrix[currow][curcol]){
                curcol--;
            }else{
                currow++;
            }
        }return false;
    }
};