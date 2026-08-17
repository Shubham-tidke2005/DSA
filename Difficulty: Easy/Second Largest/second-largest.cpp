class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int fir_lar=-1;
        int sec_lar=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>fir_lar){
                sec_lar=fir_lar;
                fir_lar=arr[i];
            }else if(arr[i]>sec_lar && arr[i]!=fir_lar){
                sec_lar=arr[i];
            }
        }return sec_lar;
    }
};