// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges

/*
Problem Statement

You need to take a singly linked list of integer value as input and print the difference between the maximum and minimum value of the singly linked list.

Note: You must use singly linked list to solve this problem, otherwise you will not get marks.

Input Format

Input will contain the values of the singly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^5; Here N is the maximum number of nodes of the linked list.
-10^9 <= V <= 10^9; Here V is the value of each node.
Output Format

Output the difference between the maximum and minimum value.
Sample Input 0

2 4 1 5 3 6 -1
Sample Output 0

5
Sample Input 1

2 -1
Sample Output 1

0
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

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

void printdif(Node* headCpy) {
    int min = INT_MAX; int max = INT_MIN;

    // Iterating and updating min max
    while(headCpy != NULL) {
        if(headCpy->val < min) min = headCpy->val;
        if(headCpy->val > max) max = headCpy->val;
        headCpy = headCpy->next;
    }

    // Printing diffrence
    cout << max - min << endl;
}

int main() {
    // Empty node
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    while(true) {
        int value; cin >> value;
        if(value == -1) break;

        insertAtTail(head, tail, value);
    }

    // Printing
    printdif(head);

    return 0;
}