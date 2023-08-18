/*
num1  = 243, num2 = 564

l1 = [2,4,3]
l2 = [5,6,4]

Result: sum = 807; L = [7,0,8]


approach

*/

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

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;
    int carry = 0;
    while ((l1 != NULL || l2 != NULL) || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next;
}

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
        Node *temp = addTwoNumbers(head1, head2);
        print(temp);
    }
    return 0;
}