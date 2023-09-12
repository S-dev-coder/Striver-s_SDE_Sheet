#include "takeinput.h"
#include <iostream>
using namespace std;

void preorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    preorder(root);
}

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

