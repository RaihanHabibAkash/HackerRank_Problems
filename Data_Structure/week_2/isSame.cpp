// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges
/*
Problem Statement

You will be given two singly linked list of integer values as input. You need to check if all the elements of both list are same which means both list are same. If they are same print "YES" otherwise print "NO".

Note: You must use singly linked list, otherwise you will not get marks.

Input Format

First line will contain the values of the first singly linked list, and will terminate with -1.
Second line will contain the values of the second singly linked list, and will terminate with -1.
Constraints

1 <= N1, N2 <= 1000; Here N1 and N2 is the maximum number of nodes of the first and second linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" or "NO".
Sample Input 0

10 20 30 40 -1
10 20 30 40 -1
Sample Output 0

YES
Sample Input 1

10 20 30 40 -1
10 20 30 -1
Sample Output 1

NO
Sample Input 2

10 20 30 40 -1
40 30 20 10 -1
Sample Output 2

NO
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

void insertAtTail(Node* &head, Node* &tail, int value) {
    // Create a new node
    Node* newNode = new Node(value);

    // Insert At head
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }

    // Connecting tail with newnode
    tail->next = newNode;
    // New node is tail now
    tail = tail->next;
}

bool checkList(Node* headCpy1, Node* headCpy2) {
    // Base case
    if(headCpy1 == NULL && headCpy2 == NULL) return true;
    if(headCpy1 == NULL || headCpy2 == NULL) return false;

    // Main case
    return (headCpy1->val == headCpy2->val) && checkList(headCpy1->next, headCpy2->next);
}

int main() {
    // Empty linked list
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;

    // Inserting for 1st linked list
    while(true) {
        int val; cin >> val;
        if(val == -1) break;
        insertAtTail(head1, tail1, val);
    }
    // Inserting for 2nd linked list
    while(true) {
        int val; cin >> val;
        if(val == -1) break;
        insertAtTail(head2, tail2, val);
    }

    // Printing
    cout << (checkList(head1, head2) ? "YES" : "NO") << endl;

    return 0;
}