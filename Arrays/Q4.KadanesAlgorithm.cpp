// Brute force approach- TC:O(N^3)

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // subarray = arr[i.....j]
            int sum = 0;

            //add all the elements of subarray:
            for (int k = i; k <= j; k++) {
                sum += arr[k];
            }

            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

// O(N^2)

int maxSubarraySum(int arr[], int n) {
    int maxi = INT_MIN; // maximum sum

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            // current subarray = arr[i.....j]

            //add the current element arr[j]
            // to the sum i.e. sum of arr[i...j-1]
            sum += arr[j];

            maxi = max(maxi, sum); // getting the maximum
        }
    }

    return maxi;
}

// optimal 
    
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxx=INT_MIN;
        
    for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        
        if(nums[i]>sum){
             sum=nums[i];
        }
        maxx=max(sum,maxx);
        
           
    }
        return maxx;  
    }
    