class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int large=-1;
        for(int i=0;i<arr.size();i++){
            large=max(arr[i],large);
        }return large;
    }
};
