// https://www.hackerrank.com/contests/assignment-02-a-basic-data-structures-a-batch-06/challenges
/*
You need to take a singly linked list of integer values as input. Afterward, you will be given an integer value X. Your task is to determine whether X is present in the linked list or not. If it is present, print its first index from the left side; otherwise, print -1. Assume that the linked list's index starts with 0.

Note: You must use a singly linked list; otherwise, you will not receive marks.

Input Format

First line will contain T, the number of test cases.
First line of each test case will contain the values of the singly linked list, and will terminate with -1.
Second line of each test case will contain X.
Constraints

1 <= T <= 100
1 <= N <= 10^5; Here N is the maximum number of nodes of the linked list.
-10^9 <= V <= 10^9; Here V is the value of each node.
-10^9 <= X <= 10^9
Output Format

Output the index of X in the linked list.
Sample Input 0

4
1 2 3 4 5 -1
3
1 2 3 -1
5
1 -1
1
10 20 -1
20
Sample Output 0

2
-1
0
1
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

int checkVal(Node* headCpy, int x, int index) {
    // Base case
    if(headCpy == NULL) return -1;

    // Main case
    if(headCpy->val == x) return index;
    return checkVal(headCpy->next, x, index+1);
}

int main() {
    // Taking input
    int cs; cin >> cs;
    while(cs--) {
        // Emty
        Node* head = NULL;
        Node* tail = NULL;

        // Taking input
        while(true) {
            int value; cin >> value;
            if(value == -1) break;
            insertAtTail(head, tail, value);
        }

        // Checking for x
        int x; cin >> x;
        int val = checkVal(head, x, 0);
        cout << val << endl;

    // Outer while end
    }

    return 0;
}