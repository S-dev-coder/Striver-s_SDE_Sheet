// recursive

// void postOrderTrav(node * curr, vector < int > & postOrder) {
//   if (curr == NULL)
//     return;

//   postOrderTrav(curr -> left, postOrder);
//   postOrderTrav(curr -> right, postOrder);
//   postOrder.push_back(curr -> data);
// }

// iterative

// vector<int> postOrderTrav(node *cur)
// {

//     vector<int> postOrder;
//     if (cur == NULL)
//         return postOrder;

//     stack<node *> st;
//     while (cur != NULL || !st.empty())
//     {

//         if (cur != NULL)
//         {
//             st.push(cur);
//             cur = cur->left;
//         }
//         else
//         {
//             node *temp = st.top()->right;
//             if (temp == NULL)
//             {
//                 temp = st.top();
//                 st.pop();
//                 postOrder.push_back(temp->data);
//                 while (!st.empty() && temp == st.top()->right)
//                 {
//                     temp = st.top();
//                     st.pop();
//                     postOrder.push_back(temp->data);
//                 }
//             }
//             else
//                 cur = temp;
//         }
//     }
//     return postOrder;
// }
