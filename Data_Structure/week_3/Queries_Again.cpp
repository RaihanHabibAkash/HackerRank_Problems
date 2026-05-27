/*
You have a doubly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

You need to insert the value V at index X. Assume that index starts from 0.
After that for each query you need to print the linked list from left to right and right to left.
If the index is invalid, then print "Invalid".
Note: You must use Doubly Linked List, otherwise you will not get marks.

Input Format

First line will contain Q.
Next Q lines will contain X and V.
Constraints

1 <= Q <= 1000;
0 <= X <= 1000;
0 <= V <= 1000
Output Format

For each query print the linked list from left to right and right to left or print "Invalid" as asked.
Print "L -> " before printing the linked list from left to right.
Print "R -> " before printing the linked list from right to left.
Sample Input 0

5
1 10
0 10
1 20
3 30
2 30
Sample Output 0

Invalid
L -> 10 
R -> 10 
L -> 10 20 
R -> 20 10 
Invalid
L -> 10 20 30 
R -> 30 20 10 
Sample Input 1

10
0 10
1 20
0 30
1 40
6 50
0 60
4 70
4 80
2 90
1 100
Sample Output 1

L -> 10 
R -> 10 
L -> 10 20 
R -> 20 10 
L -> 30 10 20 
R -> 20 10 30 
L -> 30 40 10 20 
R -> 20 10 40 30 
Invalid
L -> 60 30 40 10 20 
R -> 20 10 40 30 60 
L -> 60 30 40 10 70 20 
R -> 20 70 10 40 30 60 
L -> 60 30 40 10 80 70 20 
R -> 20 70 80 10 40 30 60 
L -> 60 30 90 40 10 80 70 20 
R -> 20 70 80 10 40 90 30 60 
L -> 60 100 30 90 40 10 80 70 20 
R -> 20 70 80 10 40 90 30 100 60 
*/
// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges
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
int sz = 0;

void printForward(Node* headCpy) {
    cout << "L -> ";
    // Iteraing to last untile pointer points last NULL
    while(headCpy != NULL) {
        cout << headCpy->val << " ";
        headCpy = headCpy->next;
    }
    cout << endl;
}

void printBackward(Node* tailCpy) {
    cout << "R -> ";
    // Iterating to 1st untile pointer point 1st NULL
    while(tailCpy != NULL) {
        cout << tailCpy->val << " ";
        tailCpy = tailCpy->prev;
    }
    cout << endl;
}

void insertAtTail(Node* &head, Node* &tail, int value) {
    Node* newNd = new Node(value);
    if(head == NULL) {
        head = newNd;
        tail = newNd;
        sz++;
        return;
    }
    
    tail->next = newNd;
    tail->next->prev = tail;
    tail = tail->next;
    sz++;
}

void insertAtHead(Node* &head, Node* &tail, int value) {
    Node* newNd = new Node(value);

    if(head == NULL) {
        head = newNd;
        tail = newNd;
        sz++;
        return;
    }

    newNd->next = head;
    head->prev = newNd;
    head = head->prev;
    sz++;
}

void insertAtAny(Node* head, int index, int value) {
    Node* newNd = new Node(value);
    Node* cur = head;
    for(int i = 0; i < index-1; i++) cur = cur->next;

    newNd->next = cur->next;
    newNd->next->prev = newNd;
    cur->next = newNd;
    newNd->prev = cur;
    sz++;
}

bool insert(Node* &head, Node* &tail, int index, int value) {
    if(index > sz || index < 0) return false;
    else if(index == sz) insertAtTail(head, tail, value);
    else if(index == 0) insertAtHead(head, tail, value);
    else insertAtAny(head, index, value);
    return true;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int q; cin >> q;
    while(q--) {
        int index, value; cin >> index >> value;
        bool flag = insert(head, tail, index, value);
        if(flag) {
            printForward(head);
            printBackward(tail);
        }
        else cout << "Invalid" << endl;
    }

    return 0;
}