/*
Problem Statement

You need to take a doubly linked list of integer value as input. You need to tell if the doubly linked list forms a palindrome or not.

Note: You need to solve this using Doubly Linked List, otherwise you will not get marks.

Input Format

Input will contain the values of the doubly linked list, and will terminate with -1.
Constraints

1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
0 <= V <= 1000; Here V is the value of each node.
Output Format

Output "YES" if it forms a palindrom otherwise output "NO".
Sample Input 0

1 2 3 2 1 -1
Sample Output 0

YES
Sample Input 1

1 2 2 1 -1
Sample Output 1

YES
Sample Input 2

1 -1
Sample Output 2

YES
Sample Input 3

1 2 3 1 -1
Sample Output 3

NO
*/
// // https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* prev;
    int val;
    Node *next;

    Node(int val) {
        prev = NULL;
        this->val = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int value) {
    Node* newNd = new Node(value);

    if(head == NULL) {
        head = newNd;
        tail = newNd;
        return; 
    }

    tail->next = newNd;
    tail->next->prev = tail;
    tail = tail->next;
}

bool isPal(Node* left, Node* right) {
    if(left == right || left->prev == right) return true;

    return (left->val == right->val) && isPal(left->next, right->prev);
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    while(true) {
        int value; cin >> value;
        if(value == -1) break;
        insertAtTail(head, tail, value);
    }

    
    cout << ( (isPal(head, tail)) ? "YES" : "NO") << endl;
    
    return 0;
}