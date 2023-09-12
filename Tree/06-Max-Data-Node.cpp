#include<iostream>
#include"tree.h"
#include<queue>
using namespace std;


TreeNode<int>* maxDataNode(TreeNode<int>*root)
{
    // Edge case
    if(root == NULL)
    {
        return 0;
    }

    // Created a maxdata variable which will store the max data of Node
    int maxdata = root->data;

    // Created a variable for storing Node. which we will use to store and  return as the max Node
    TreeNode<int>* Node = root;

    // Recursive call for each node
    for(int i = 0; i < root->children.size(); i++)
    {
        // Storing each node in temp for each iteration 
        TreeNode<int>*temp = maxDataNode(root->children[i]);
        // Checking whether the data of current node is greater than the maxdata
        // if yes then update the max data with the new maxdata and also update the Node with new temp node
        if(temp->data > maxdata)
        {
            maxdata = temp->data;
            Node = temp;
        }
        // Simply return the Node which is keeping the maxdata
        return Node;
    }
}


void PrintNodeLevelWise(TreeNode<int>*root)
{
    // Edge Case for in case if the use gives NULL data then simply return
    if(root == NULL)
    {
        return;
    }
    
    // 01 Created a Queue which will store the pending Nodes of tree for Printing
    queue<TreeNode<int>*>pendingNodes;

    // 02 Pushing the root element in the queue
    pendingNodes.push(root);

    // 03 Running the while loop till the size of pendingNode Queue is not 0
    while(pendingNodes.size() != 0)
    {
        // 03.1 Created the front node which will store the first element of queue 
        TreeNode<int>*front = pendingNodes.front();

        // 03.2 Removing the front element of queue
        pendingNodes.pop();

        // 03.3 Printing the element of children level wise
        cout << front->data << ":";

        // Running the loop which will print the element of children
        for(int i = 0; i < front->children.size(); i++)
        {
            // If the element is at 0th index simply print it
            if(i == 0)
            {
                cout << front->children[i]->data;
            }
            // Else put a comma "," and then print the element
            else
            {
                cout << "," << front->children[i]->data;
            }
            // Then push each element in the queue
            pendingNodes.push(front->children[i]);
        }
        // Print the element in next line once the element of one level is completed
        cout << endl;
    }
//       10
//     / | \""
//  20   30 40
//  /\ 
//40  50

// 10
// 10: 20,30,40
// 20: 40,50
// 30:
// 40:

}


TreeNode<int>*takeInputLevelWise()
{
    int rootData;
    // cout << "Enter root data "<< endl;
    cin >> rootData;
    TreeNode<int>*root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0)
    {
        TreeNode<int>*front = pendingNodes.front();
        pendingNodes.pop();
        // cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            // cout << "Enter" << i << "th child of "<< front-> data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
        
    }
    return root;
}


int main()
{

}