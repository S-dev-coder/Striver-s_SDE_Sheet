// to generate all permutaions-Time complexity of O(N!xN).Space Complexity-O(1).

void Nextpermute(int index,vector<int> &nums,vector<vector<int>> &ans){
    if(index==nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]);
        NextPermute(index+1,nums,ans);
        swap(nums[index],nums[i]);
    }
}

vector<vector<int>> Permute(vector<int> & ans){
    vector<vector<int>> ans;
    NextPermute(0,nums,ans);
    return ans;
}


// by using inbuild functions

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1,3,2};
    
    next_permutation(arr,arr+3);//using in-built function of C++
    
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2];
    
    return 0;
}

//optimal solution - TC:O(3N).Space Complexity:O(1).
