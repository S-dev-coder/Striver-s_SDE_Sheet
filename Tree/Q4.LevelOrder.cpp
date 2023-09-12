//  vector<vector<int>> levelOrder(TreeNode* root) {
     
//         vector<vector<int>> res;
//         if(root==NULL)
//             return res;
        
//         queue<TreeNode*> Q;
//         Q.push(root);
        
//         while(!Q.empty()){
//               vector< int> ans;
//             int n=Q.size();
//               for(int i=0;i<n;i++){
//             TreeNode* temp=Q.front();   
//             Q.pop();
//         if(temp->left!=NULL)
//             Q.push(temp->left);
//         if(temp->right!=NULL)
//             Q.push(temp->right);
//         ans.push_back(temp->val);
           
//         }
//          res.push_back(ans);
//         }
//         return res;
//     } 