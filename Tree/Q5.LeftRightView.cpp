
// Intuition: We have to do a Recursive Level Order Traversal.

// Root Right Left     —-> for Right view

// Root Left Right     —–> for Left view



// --> left view

//   void recursion(TreeNode *root, int level, vector<int> &res)
//     {
//         if(root==NULL) return ;
//         if(res.size()==level) res.push_back(root->val);
//         recursion(root->left, level+1, res);
//         recursion(root->right, level+1, res);
//     }
    
//     vector<int> leftSideView(TreeNode *root) {
//         vector<int> res;
//         recursion(root, 0, res);
//         return res;
//     }


// ---> Right View

//   void recursion(TreeNode *root, int level, vector<int> &res)
//     {
//         if(root==NULL) return ;
//         if(res.size()==level) res.push_back(root->val);
//         recursion(root->right, level+1, res);
//         recursion(root->left, level+1, res);
//     }
    
//     vector<int> rightSideView(TreeNode *root) {
//         vector<int> res;
//         recursion(root, 0, res);
//         return res;
//     }