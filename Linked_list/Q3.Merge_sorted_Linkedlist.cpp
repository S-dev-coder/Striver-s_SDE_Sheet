// Input Format :
// l1 = {3,7,10}, l2 = {1,2,5,8,10}

// Output :
// {1,2,3,5,7,8,10,10}

// optimal

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

Node *mergeTwoLists(Node *l1, Node *l2)
{
    int data;
    Node *p = l1;
    Node *q = l2;
    Node *r = l1;
    if (l1 == NULL)
    {
        return l2;
    }
    else if (l2 == NULL)
    {
        return l1;
    }
    if (l1->data <= l2->data)
    {
        r = l1;
        r->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        r = l2;
        r->next = mergeTwoLists(l2->next, l1);
    }
    return r;
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
        Node *head1 = takeinput();
        Node *head2 = takeinput();
        Node *temp = mergeTwoLists(head1, head2);
        print(temp);
    }
    return 0;
}
