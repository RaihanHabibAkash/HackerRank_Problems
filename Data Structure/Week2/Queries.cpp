// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges
/*
Problem Statement

You have a singly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

If X is 0 that means you will insert the value V to the head of the linked list.
If X is 1 then you will insert the value V to the tail of the linked list.
If X is 2 then you will delete the value Vth index of the linked list. Assume that index starts from 0. If the index is invalid, then you shouldn't perform the deletion.
After each query you need to print the linked list.
Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 2;
0 <= V <= 10^9
Output Format

For each query ouput the updated linked list.
Sample Input 0

4
0 10
1 20
1 30
0 40
Sample Output 0

10 
10 20 
10 20 30 
40 10 20 30 
Sample Input 1

11
0 10
2 5
1 20
1 30
0 40
2 0
0 50
2 2
1 60
2 3
2 3
Sample Output 1

10 
10 
10 20 
10 20 30 
40 10 20 30 
10 20 30 
50 10 20 30 
50 10 30 
50 10 30 60 
50 10 30 
50 10 30 
Sample Input 2

10
1 4
2 1
0 9
0 10
2 2
1 5
2 0
2 1
2 5
2 2
Sample Output 2

4 
4 
9 4 
10 9 4 
10 9 
10 9 5 
9 5 
9 
9 
9 
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node *next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int value) {
    // Create new node
    Node* newNode = new Node(value);

    // If linked list is empty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connect new node with head
    newNode->next = head;
    // New node is head now
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Create new node
    Node* newNode = new Node(value); 

    // Linked list is emty
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connect new node with tail
    tail->next = newNode;
    // New node is tail now
    tail = tail->next;
}

int listSize(Node* headCpy) {
    // Base case
    if(headCpy == NULL) return 0;

    // Main case
    return 1 + listSize(headCpy->next);
}

void dltFromHead(Node* &head, Node* &tail) {
    // One node only and deleting it
    if(head == tail) {
        // Deleting the node
        delete head;
        // Head & tail is NULL now
        head = NULL; tail = NULL;
        return;
    }

    // Pointer that will point delete node
    Node* dltNode = head;
    // Move head to next node
    head = head->next;
    // Delete the node
    delete dltNode;
}

void dltFromTail(Node* &head, Node* &tail) {
    // Deleting the last node
    if(head == tail) {
        // Deleting the node
        delete head;
        // Head & tail is NULL now
        head = NULL; tail = NULL; 
        return;
    }

    // Point the node we want to delete
    Node* dltNode = tail;
    // Iterate till (last-1) node
    Node* current = head;
    while(current->next != tail) current = current->next;

    // current node will point NULL
    current->next = NULL;
    // Moving the tail into current node
    tail = current;
    // deleting the node
    delete dltNode;
}

void dltAtIndex(Node* &head, Node* &tail, int index) {
    // delete last node
    if(head == tail) {
        // Delete the last node
        delete head;
        // head & tail will point NULL
        head = NULL; tail = NULL;
        return;
    }

    // Traversing thorough (index-1) node
    Node* current = head;
    for(int i = 0; i < index-1; i++) current = current->next;

    // We are in delete node before node
    Node* dltNode = current->next;
    // Connect the current Node with the (dltnode+1) node
    current->next = current->next->next;
    // Delte the dlt node
    delete dltNode;
}

void dltAtAny(Node* &head, Node* &tail, int index) {
    // Checking if the index is valid
    if(listSize(head) <= index || index < 0) return;

    // Delete from head
    if(index == 0) dltFromHead(head, tail);
    else if(index == listSize(head)-1) dltFromTail(head, tail);
    else dltAtIndex(head, tail, index);
}

void priting(Node* headCpy) {
    // Base case
    if(headCpy == NULL) {
        cout << endl;
        return;
    }

    cout << headCpy->val << " ";

    // Main case
    priting(headCpy->next);
}

int main() {
    // Emty linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Taking case
    int cs; cin >> cs;
    while(cs--) {
        // Taking input
        int x, val; cin >> x >> val;

        // Base on the input operations
        if(x == 0) insertAtHead(head, tail, val);
        else if(x == 1) insertAtTail(head, tail, val);
        else if(x == 2) dltAtAny(head, tail, val);

        // Printing
        priting(head);
    }

    return 0;
}