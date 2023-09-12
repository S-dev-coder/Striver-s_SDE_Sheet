#include <iostream>
#include "tree.h"
#include <queue>
using namespace std;

// Recursion

// vector<int> vec;
// vector<int> inorderTraversal(TreeNode *root)
// {
//     if (root == nullptr)
//         return {};
//     inorderTraversal(root->left);
//     vec.push_back(root->val);
//     inorderTraversal(root->right);
//     return vec;
// }



// Iterative

// vector<int> inOrderTrav(node *curr)
// {
//     vector<int> inOrder;
//     stack<node *> s;
//     while (true)
//     {
//         if (curr != NULL)
//         {
//             s.push(curr);
//             curr = curr->left;
//         }
//         else
//         {
//             if (s.empty())
//                 break;
//             curr = s.top();
//             inOrder.push_back(curr->data);
//             s.pop();
//             curr = curr->right;
//         }
//     }
//     return inOrder;
// }


// Morris Inorder

