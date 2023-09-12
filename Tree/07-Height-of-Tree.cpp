#include <iostream>
#include <queue>
#include"tree.h"
using namespace std;


int getHeight(TreeNode<int>*root)
{
    // Edge case 
    if(root == NULL)return 0;

    // this will store the height of the tree
    int ans = 0;
    // Running the loop which will give recursive call to get the height from the nodes
    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeight = getHeight(root->children[i]);
        if(childHeight > ans)
        {
            ans = childHeight;
        }
        
    }
    // Returning the answer with +1 as we counted that node as 1 height
    return ans+1;
    
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
    cout << getHeight(root);
}

