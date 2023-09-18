// Brute force - Time Complexity: O(N)  Space Complexity: O(1)

#include<bits/stdc++.h>
using namespace std;
double myPow(double x, int n) {
      double ans = 1.0;
      for (int i = 0; i < n; i++) {
        ans = ans * x;
      }
      return ans;
}
int main()
{
    cout<<myPow(2,10)<<endl;
}

// optimal approach O(logn) o(1)

