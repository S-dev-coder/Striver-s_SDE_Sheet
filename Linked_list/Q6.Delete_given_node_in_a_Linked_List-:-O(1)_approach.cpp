
// Example 1:
// Input:
//  Linked list: [1,4,2,3]
//        Node = 2
// Output:
// Linked list: [1,4,3]
// Explanation: Access is given to node 2. After deleting nodes, the linked list will be modified to [1,4,3].

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

// function to get reference of the node to delete
Node *getNode(Node *head, int val)
{
    while (head->data != val)
        head = head->next;

    return head;
}
// delete function as per the question
void deleteNode(Node *t)
{
    t->data = t->next->data;
    t->next = t->next->next;
    return;
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
        int n;
        cin >> n;
        Node *head = takeinput();
        Node *temp = getNode(head,n);
        deleteNode(temp);
        print(head);
    }
    return 0;
}