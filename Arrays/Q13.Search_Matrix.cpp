// Brute Force - O(N*M) O(1)

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        bool check = false;
     for(int i=0;i<n;i++){
         for(int j=0;j<m;j++){
             if(matrix[i][j]==target)
                 check= true;
         }
     }
        return check;  
    }



    // optimal approach  -Time Complexity: O(log(NxM))Space Complexity: O(1)
 
// we have to apply binary search in 2D matrix . so how we do that we will just access the index of array by changing the way of accessing its rows and columns
// row=mid/m col=mid&m 


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    //apply binary search:
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int row = mid / m, col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
