#include <iostream>
#include"tree.h"
#include<queue>
using namespace std;

// Printing the trees and its childrens
void printTree(TreeNode<int>* root)
{
    // Edge case its not a base case
    if(root == NULL)
    {
        return;
    }

    cout << root->data << ":";
    // Here we are selecting first root and printing its childrens
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    // Recursive call without base case as there is single node so its automatically taking it as a base case for other tree nodes
    for(int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}




TreeNode<int>*takeInputLevelWise()
{
    // getting the root data
    int rootData;
    cout << "Enter root data "<< endl;
    cin >> rootData;

    // Creating Root node
    TreeNode<int>*root = new TreeNode<int>(rootData);

    // Using Queue with int type pointer data which will store the pending nodes
    queue<TreeNode<int>*> pendingNodes;

    // Pusing the first node in the queue for the input operation
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        // Storing the front element of the queue for data input
        TreeNode<int>*front = pendingNodes.front();
        // Removing the front element from the thinking the input of that element is done
        pendingNodes.pop();
        // Asking for number of children should be made
        cout << "Enter num of children of " << front->data << endl;
        // Taking the number of node    
        int numChild;
        cin >> numChild;
        
        
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter" << i << "th child of "<< front-> data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }
    return root;
}



int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);
}





