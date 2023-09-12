#include<iostream>
#include<queue>
#include"tree.h"
using namespace std;

int sumOfNodes(TreeNode<int>* root) {
    // Storing the data of root node into ans variable
    int ans = root->data;

    // Running a loop and giving the recursive call for all the childrens of root
    for(int i = 0; i < root->children.size(); i++)
    {
        // Giving the recursive call and storing the value in ans variable
        ans = ans+sumOfNodes(root->children[i]);
    }
    // returning the ans variable
    return ans;
}


TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << sumOfNodes(root);
}