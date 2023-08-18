// Input: height= [0,1,0,2,1,0,1,3,2,1,2,1]

// Output: 6

// Explanation: As seen from the diagram 1+1+2+1+1=6 unit of water can be trapped

// brute force

#include <bits/stdc++.h>

using namespace std;
int trap(vector<int> &arr)
{
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}

int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
}

// optimal approach

#include <bits/stdc++.h>

using namespace std;
int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;

    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
}

int main()
{
    vector<int> arr;
    arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "The water that can be trapped is " << trap(arr) << endl;
}
