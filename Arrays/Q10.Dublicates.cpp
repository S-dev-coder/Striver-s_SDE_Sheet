// Brute force approach -- Time Complexity:O(Nlogn + N)- SC - O(1)

#include<bits/stdc++.h>

using namespace std;
int findDuplicate(vector < int > & arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] == arr[i + 1]) {
      return arr[i];
    }
  }
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,2};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}


// // Optimal Approach
// Time Complexity: O(N), as we are traversing through the array only once.

// Space Complexity: O(N), as we are using extra space for frequency array.

int ans;
int H[n+1]={0};
for(int i=0;<n;i++){
    H[arr[i]]++;
}
for(int i=0;i<n;i++){
    if(H[arr[i]]>1)
    ans=arr[i];
}
return ans;