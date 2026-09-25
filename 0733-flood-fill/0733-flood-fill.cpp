class Solution {
public:

    //helper function
    void change_color(vector<vector<int>>& image, int sr, int sc, long long int reqcolor,int n,int m,long long int currcolor){
        
        if(sr<0 || sc<0 || sr>n || sc>m || image[sr][sc]!=currcolor){
            return ;
        }

        image[sr][sc]=reqcolor;
        change_color(image, sr-1, sc,reqcolor,n,m,currcolor);
        change_color(image, sr, sc-1,reqcolor,n,m,currcolor);
        change_color(image, sr+1, sc,reqcolor,n,m,currcolor);
        change_color(image, sr, sc+1,reqcolor,n,m,currcolor);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size()-1;
        int m=image[0].size()-1;
        long long currcolor=image[sr][sc];
        if (currcolor == color) {
            return image;
        }

        change_color(image, sr, sc,color,n,m,currcolor);
        return image;
    }
};