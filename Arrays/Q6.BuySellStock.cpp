 // brute force-- Time complexity: O(n^2) -Space Complexity: O(1)
    
    int maxProfit(vector<int>& prices) {
        int profit,maxi=0;
        
       for(int i=0;i<prices.size()-1;i++){
           for(int j=i+1;j<prices.size();j++){
           profit = prices[j]-prices[i];
               maxi= max(profit,maxi);
       } 
       } 
        
        
        return maxi;  
    }
    
    
    // optimal-- TC-O(N) SC:O(1).
    int maxProfit(vector<int> &prices) {
    int maxPro = 0;
    int n = prices.size();
    int minPrice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }
    
    return maxPro;
}