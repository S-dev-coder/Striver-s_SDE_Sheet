
 // Brute Force Approach - Time Complexity: O((N*M)*(N + M)) + O(N*M)- Space Complexity: O(1)

    void setrow(vector<vector<int>>& matrix,int n, int m,int i){
   
        for(int j=0;j<m;j++){
        if(matrix[i][j]!=0)
            matrix[i][j]=-1;
    }
    }
     void setcol(vector<vector<int>>& matrix,int n, int m,int j){
       
        for(int i=0;i<n;i++){
        if(matrix[i][j]!=0)
            matrix[i][j]=-1;
    }
    
     }
    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                 setrow(matrix,n,m,i);
                 setcol(matrix,n,m,j);
            }
               
        }
        }
        
        
        for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){
       
        if(matrix[i][j]==-1)
            matrix[i][j]=0;
    }
        }
        
    }
    
    
    // Optimal Approach -Time Complexity: O(2*(N*M)), - space complexity - O(N).
    
     void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<bool> rowToModify(n, false);
        vector<bool> colToModify(m, false);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    rowToModify[i] = true;
                    colToModify[j] = true;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rowToModify[i] || colToModify[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
    
    
    
    