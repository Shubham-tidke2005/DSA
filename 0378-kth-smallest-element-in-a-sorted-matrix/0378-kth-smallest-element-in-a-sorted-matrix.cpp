class Solution {
public:
    int kitiChoteAhe(vector<vector<int>>& matrix, int ele){
        //checks each row having ele smaller than equal ele
        int totalminele=0;
        for(int i=0;i<matrix.size();i++){
            int st=0;
            int end=matrix.size()-1;
            int rowsmall = -1;
            while(st<=end){
                int mid=st+((end-st)/2);
                if(matrix[i][mid]<=ele){
                    rowsmall=max(rowsmall,mid);
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            } totalminele += (rowsmall + 1);
        }return totalminele;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int st=matrix[0][0];
        int end=matrix[matrix.size()-1][matrix.size()-1];
        while(st<end){
            int mid=st+(end-st)/2;
            int totalminele=kitiChoteAhe(matrix,mid);
            if(totalminele<k){
                st=mid+1;
            }else{
                end=mid;
            }
        }return st;
    }
};