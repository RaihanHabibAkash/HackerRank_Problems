/*
There is a list of  values that were inserted into a stack and a list of  values that were inserted into a queue. You need to determine whether the stack and queue are the same or not based on the order in which the elements are removed.

Note: You cannot use any  here. You need to implement the stack and queue by yourself. You can use linked list or array as you want.

Input Format

First line will contain  and .
Second line will contain stack  with  values.
Third line will contain queue  with  values.
Constraints

Output Format

Output YES if they were same, otherwise NO.
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
1 2 3 4 5
5 4 3 2
Sample Output 2

NO
*/
// https://www.hackerrank.com/contests/assignment-03-a-basic-data-structure-a-batch-06/challenges
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

class Stack {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        Node* newNd = new Node(val);
        sz++;
        // Empty linked list
        if(head == NULL) {
            head = newNd;
            tail = newNd;
            return;
        }

        // Connections
        newNd->next = head;
        head = newNd;
    }
    void pop() {
        // Empty linked list
        if(head == NULL) return;

        sz--;
        // One linked list only
        if(head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        // Connections
        Node* dltNd = head;
        head = head->next;
        delete dltNd;
    }
    int top() {
        if(head == NULL) return -1;

        return head->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return head == NULL;
    }
};

class Queue {
public:
    Node* head = NULL;
    Node* tail = NULL;
    int sz = 0;

    void push(int val) {
        Node* newNd = new Node(val);
        sz++;
        // Empty linked list
        if(head == NULL) {
            head = newNd;
            tail = newNd;
            return;
        }

        // Connection
        tail->next = newNd;
        tail = tail->next;
    }
    void pop() {
        if(head == NULL) return;

        sz--;
        // One value is left only
        if(head->next == NULL) {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node* dltNd = head;
        head = head->next;
        delete dltNd;
    }
    int front() {
        if(head == NULL) return -1;

        return head->val;
    }
    int back() {
        if(tail == NULL) return -1;

        return tail->val;
    }
    int size() {
        return sz;
    }
    bool empty() {
        return head == NULL;
    }
};

int main() {
    int n, m; cin >> n >> m;
    stack<int> st;
    queue<int> q;
    bool flag = true;

    // Inserting values in stack
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        st.push(val);
    }
    // Inserting values in queue
    for(int i = 0; i < m; i++) {
        int val; cin >> val;
        q.push(val);
    }

    // Checking values
    if(st.size() != q.size()) flag = false;
    else { // stack & queue size are same
        while(!st.empty()) {
            if(st.top() != q.front()) {
                flag = false;
                break;
            }

            st.pop();
            q.pop();
        }
    }

    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}