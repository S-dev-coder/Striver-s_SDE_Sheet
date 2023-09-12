#include <iostream>
// #include<vector>
#include "tree.h"
using namespace std;

// Take Input Function
TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    // This is for Number of Call we need to make for putting the value
    // in the children for each root element
    int n;
    cout << "Enter the number of children of " << rootData << ":";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    // Edge case its not a base case
    if (root == NULL)
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
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(node2);

    TreeNode<int> *root = takeInput();

    printTree(root);
}