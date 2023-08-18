// Input Format: 
// ( Pointer / Access to the head of a Linked list )
// head = [1,2,3,4,5]

// Result: [3,4,5]



// brute force 

#include <iostream>
using namespace std;

// Node Class for LinkedList
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

// BRUTE FORCE 

//  Node* middleNode(Node* head) {
//     	int n = 0;
//     Node* temp = head;
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



// OPTIMAL 

 Node* middleNode(Node* head) {
      Node *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next;
             fast = fast->next->next;
        return slow;
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
        Node *head = takeinput();
        Node *temp= middleNode(head);
        print(temp);
    }
    return 0;
}