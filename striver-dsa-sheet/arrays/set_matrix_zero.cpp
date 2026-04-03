//https://leetcode.com/problems/set-matrix-zeroes/description/

/*

I used separate arrays for this but then I used the first row and column for 
the purpose. Iterating from 1 to avoid setting first row or column falsely 
zero.

*/

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            int n=matrix.size();
            int m=matrix[0].size();
    
            // vector<bool> row(n,1);
            // vector<bool> column(m,1);
    
            bool isFrontRow0=false;
            bool isFrontCol0=false;
    
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(matrix[i][j]==0){
                        // row[i]=0;
                        // column[j]=0;
                        matrix[i][0]=0;
                        matrix[0][j]=0;
                        if(i==0)isFrontRow0=true;
                        if(j==0)isFrontCol0=true;
                    }
                }
            }
    
            for(int i=1;i<n;i++){
                for(int j=1;j<m;j++){
                    // if(row[i]==0 || column[j]==0){
                    //     matrix[i][j]=0;
                    // }
    
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
    
            if(isFrontCol0){
                for(int i=0;i<n;i++)matrix[i][0]=0;
            }
            if(isFrontRow0){
                for(int i=0;i<m;i++)matrix[0][i]=0;
            }
        }
    };