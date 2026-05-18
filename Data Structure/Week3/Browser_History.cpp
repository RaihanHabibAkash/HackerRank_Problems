/*
You are given a doubly linked list of unique string values. These strings refer to web addresses without any spaces. You will be given Q queries. In each query you will be given some commands. Type of commands are -

visit address - You need to go to that address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
next - You need to go to the next address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
prev - You need to go to the previous address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
One more thing, if the address isn't available make sure you don't move from your current position. You are at the head initially.

Note: You can use Singly/Doubly Linked List or STL List to solve this problem.

Input Format

First line will contain the values of the doubly linked list, and will terminate with the string "end".
Second line will contain Q.
Next Q lines will contain the commands. It is guranteed that you will get "visit address" command at first which will contain a valid address. It will not contain valid address everytime!
Constraints

1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
1 <= Q <= 1000;
1 <= |Address| <= 100; Here |Address| is the length of the string address.
Output Format

For each query output as asked.
Sample Input 0

facebook google phitron youtube twitter end
12
visit phitron
prev
prev
prev
prev
next
visit twitter
next
next
prev
visit django
prev
Sample Output 0

phitron
google
facebook
Not Available
Not Available
google
twitter
Not Available
Not Available
youtube
Not Available
phitron
Sample Input 1

a b c d e f g h i j k l m n o p q r s t u v w x y z end
7
visit s
next
visit zz
next
visit z
next
prev
Sample Output 1

s
t
Not Available
u
z
Not Available
y
*/
// https://www.hackerrank.com/contests/mid-term-exam-a-basic-data-structures-a-batch-06/challenges
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node* prev;
    string val;
    Node* next;

    Node(string val) {
        prev = NULL;
        this->val = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, string value) {
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

string checkUrl(Node* &cur, Node* headCpy, string url) {
    if(headCpy == NULL) return "Not Available";

    if(headCpy->val == url) {
        cur = headCpy;
        return url;
    } 
    else return checkUrl(cur, headCpy->next, url);
}

string nextNd(Node* &cur) {
    if(cur->next != NULL) {
        cur = cur->next;
        return cur->val;
    }
    else return "Not Available";
}

string prevNd(Node* &cur) {
    if(cur->prev != NULL) {
        cur = cur->prev;
        return cur->val;
    }
    else return "Not Available";
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    // Taking input
    while(true) {
        string lekha; cin >> lekha;
        if(lekha == "end") break;
        insertAtTail(head, tail, lekha);
    }

    // queries
    int q; cin >> q;
    Node* cur = head;
    while(q--) {
        string val; cin >> val;
        if(val == "visit") {
            string url; cin >> url;
            cout << checkUrl(cur, head, url) << endl;
        }
        else if(val == "next") cout << nextNd(cur) << endl;
        else if(val == "prev") cout << prevNd(cur) << endl;
    }

    return 0;
}