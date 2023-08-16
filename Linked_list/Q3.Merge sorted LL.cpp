// Input Format :
// l1 = {3,7,10}, l2 = {1,2,5,8,10}

// Output :
// {1,2,3,5,7,8,10,10}



// optimal



// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         int val;
//         ListNode *p=l1;
//          ListNode *q=l2;
//          ListNode *r=l1;
//         if(l1==nullptr){
//             return l2;
//         }
//         else if(l2==nullptr){
//             return l1;
//         }
//         if(l1->val<= l2->val ){
//             r=l1;
//             r->next =  mergeTwoLists(l1->next,l2);
//         }
//         else
//         {
//             r=l2;
//             r->next =mergeTwoLists(l2->next,l1);
//         }
//         return r;
//     }
// };

