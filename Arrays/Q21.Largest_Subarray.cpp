// Brute force solution --Time Complexity: O(N2)  Auxiliary Space: O(1)


int maxLen(int arr[], int N)
{

    int max_len = 0;
    for (int i = 0; i < N; i++) {
        int curr_sum = 0;
        for (int j = i; j < N; j++) {
            curr_sum += arr[j];
            if (curr_sum == 0)
                max_len = max(max_len, j - i + 1);
        }
    }
    return max_len;
}
 

// Optimal solution -- Time Complexity: O(N)  Auxiliary Space: O(N)

int maxLen(int A[], int n)
{
   
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}
