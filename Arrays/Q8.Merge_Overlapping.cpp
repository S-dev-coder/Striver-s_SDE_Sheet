// Brute Force Approach -- Time Complexity: O(N*logN) + O(2*N), SC- O(N)

vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        
        
        for(int i=0;i<intervals.size();i++){
            int start = intervals[i][0];
            int end= intervals[i][1];
            
            if(!ans.empty()&& end<=ans.back()[1])
                continue;
            
            for(int j=i+1;j<intervals.size();j++){
                if(intervals[j][0]<=end)
                    end=max(end,intervals[j][1]);
                else
                    break;
            }
            ans.push_back({start,end});
        }
        return ans;
    }


// Optimal Approach -- Time Complexity: O(N*logN) + O(N)-- SC:- Space Complexity: O(N)

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
