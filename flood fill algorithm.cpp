// ques-733 leetcode
//using DFS
class Solution {
public:
        
        void dfs(int sr,int sc,int start,vector<vector<int>>& image,vector<vector<int>>& newmatrix,int row[],int col[],int color)
        {
                newmatrix[sr][sc]=color;
                
                for(int i=0;i<4;i++)
                {
                    //find neighbours
                    int nrow=sr+row[i];    
                    int ncol=sc+col[i];
                 
                        //check valid or not
                   if(nrow>=0 && nrow<image.size() && ncol>=0 &&ncol<image[0].size())
                   {
                            //now check for same initial color and visited or not
                  if(image[nrow][ncol]==start && newmatrix[nrow][ncol]!=color)
                           {
                                   dfs(nrow,ncol,start,image,newmatrix,row,col,color);
}
                   }
                        
                }
        }
        
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int start=image[sr][sc];
        vector<vector<int>> newmatrix;
            newmatrix=image;
            int row[]={-1,0,1,0};
            int col[]={0,1,0,-1};
           
       dfs(sr,sc,start,image,newmatrix,row,col,color);
                return newmatrix;
    }
};
