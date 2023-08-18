// Example 1:
// Input:
// List 1 = [1,3,1,2,4], List 2 = [3,2,4]
// Output:
// 2

// brute force

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// utility function to insert node at the end of the linked list
//  void insertNode(Node* &head,int val) {
//      Node* newNode = new Node(val);
//      if(head == NULL) {
//          head = newNode;
//          return;
//      }
//      Node* temp = head;
//      while(temp->next != NULL) temp = temp->next;
//      temp->next = newNode;
//      return;
//  }

// utility function to check presence of intersection
Node *intersectionPresent(Node *head1, Node *head2)
{
    unordered_set<Node *> st;
    while (head1 != NULL)
    {
        st.insert(head1);
        head1 = head1->next;
    }
    while (head2 != NULL)
    {
        if (st.find(head2) != st.end())
            return head2;
        head2 = head2->next;
    }
    return NULL;
}

// Input taking Function
Node *takeinput()
{
    // Taking first value for creating and also for head node
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;

    // Running a loop till user doesn't gives -1 as input
    while (data != -1)
    {
        // Creating Head node
        Node *newNode = new Node(data);

        // Checking if head is null(showing if the linked list is present or not) if not then create it
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }

        // Else there is a head node then start using tail as traversal and attaching new node which is created
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        // Again taking input for next node which will be attached to the list or terminating the LL if provided -1
        cin >> data;
    }
    // Now returning head for providing the LL
    return head;
}

// //utility function to print linked list created
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<endl;
// }

// Print Function
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Driver Code
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *temp = intersectionPresent(head1,head2);
        print(temp);
    }
    return 0;
}

// int main() {
//     // creation of both lists
//     node* head = NULL;
//     insertNode(head,1);
//     insertNode(head,3);
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,4);
//     node* head1 = head;
//     head = head->next->next->next;
//     node* headSec = NULL;
//     insertNode(headSec,3);
//     node* head2 = headSec;
//     headSec->next = head;
//     //printing of the lists
//     cout<<"List1: "; printList(head1);
//     cout<<"List2: "; printList(head2);
//     //checking if intersection is present
//     node* answerNode = intersectionPresent(head1,head2);
//     if(answerNode == NULL )
//     cout<<"No intersection\n";
//     else
//     cout<<"The intersection point is "<<answerNode->num<<endl;
//     return 0;
// }

// optimal approach

// #include<bits/stdc++.h>
// using namespace std;

// class node {
//     public:
//         int num;
//         node* next;
//         node(int val) {
//             num = val;
//             next = NULL;
//         }
// };
// //utility function to insert node at the end of the linked list
// void insertNode(node* &head,int val) {
//     node* newNode = new node(val);
//     if(head == NULL) {
//         head = newNode;
//         return;
//     }

//     node* temp = head;
//     while(temp->next != NULL) temp = temp->next;

//     temp->next = newNode;
//     return;
// }
// //utility function to check presence of intersection
// node* intersectionPresent(node* head1,node* head2) {
//     node* d1 = head1;
//     node* d2 = head2;

//     while(d1 != d2) {
//         d1 = d1 == NULL? head2:d1->next;
//         d2 = d2 == NULL? head1:d2->next;
//     }

//     return d1;
// }

// //utility function to print linked list created
// void printList(node* head) {
//     while(head->next != NULL) {
//         cout<<head->num<<"->";
//         head = head->next;
//     }
//     cout<<head->num<<endl;
// }

// int main() {
//     // creation of both lists
//     node* head = NULL;
//     insertNode(head,1);
//     insertNode(head,3);
//     insertNode(head,1);
//     insertNode(head,2);
//     insertNode(head,4);
//     node* head1 = head;
//     head = head->next->next->next;
//     node* headSec = NULL;
//     insertNode(headSec,3);
//     node* head2 = headSec;
//     headSec->next = head;
//     //printing of the lists
//     cout<<"List1: "; printList(head1);
//     cout<<"List2: "; printList(head2);
//     //checking if intersection is present
//     node* answerNode = intersectionPresent(head1,head2);
//     if(answerNode == NULL )
//     cout<<"No intersection\n";
//     else
//     cout<<"The intersection point is "<<answerNode->num<<endl;
//     return 0;
// }
