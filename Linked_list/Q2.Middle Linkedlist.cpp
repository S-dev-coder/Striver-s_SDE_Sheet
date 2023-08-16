// Input Format: 
// ( Pointer / Access to the head of a Linked list )
// head = [1,2,3,4,5]

// Result: [3,4,5]

// brute force 

// class Solution {
// public:
// 	ListNode* middleNode(ListNode* head) {
//     	int n = 0;
//     	ListNode* temp = head;
//     	while(temp) {
//         	n++;
//         		temp = temp->next;
//     	}
   	 
//     	temp = head;
   	 
//     	for(int i = 0; i < n / 2; i++) {
//         		temp = temp->next;
//     	}
   	 
//     	return temp;
// 	}
// };




// optimal
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode *slow = head, *fast = head;
//         while (fast && fast->next)
//             slow = slow->next;
//              fast = fast->next->next;
//         return slow;
//     }
// };


