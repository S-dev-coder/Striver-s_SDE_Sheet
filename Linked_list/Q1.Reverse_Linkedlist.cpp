// Input Format:
// head = [3,6,8,10]
// // This means the given linked list is 3->6->8->10 with head pointer at node 3.

// BRUTE FORCE / ITERATIVE

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

Node *reverseList(Node *head)
{

    Node *prev_p = NULL;
    Node *current_p = head;
    Node *next_p;

    // step 2
    while (current_p)
    {

        next_p = current_p->next;
        current_p->next = prev_p;

        prev_p = current_p;
        current_p = next_p;
    }

    head = prev_p; // step 3
    return head;
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
        Node *temp = reverseList(head);
        print(temp);
    }
    return 0;
}

// RECURSIVE APPROACH

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
// ---------------------------------------------
Node *reverseList(Node *&head)
{

    if (head == NULL || head->next == NULL)
        return head;

    Node *nnode = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return nnode;
}
// ---------------------------------------------

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
        Node *temp = reverseList(head);
        print(temp);
    }
    return 0;
}
