/*
You will be given a binary tree as input in level order. Also you will be given a level . You need to print all the node's values in that level from left to right. Assume that level starts from .

For example:

image

If , then the output for the above tree will be: 40 50 60

Note: If the level  is not a valid level, the print "Invalid".

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output all the node's values in level .
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
0
Sample Output 0

10
Sample Input 1

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
1
Sample Output 1

20 30
Sample Input 2

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
2
Sample Output 2

40 50 60
Sample Input 3

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
3
Sample Output 3

Invalid
*/
// https://www.hackerrank.com/contests/assignment-04-a-basic-data-structure-a-batch-06/challenges
#include <bits/stdc++.h>
using namespace std;

class Bnode {
public:
    int val;
    Bnode* left;
    Bnode* right;

    Bnode(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

Bnode* input_tree() {
    int val; cin >> val;
    Bnode* root;
    if(val == -1) {
        root = NULL;
        return root;
    }
    else root = new Bnode(val);

    // Creating queue of pairs, pairs of node & int level
    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
    // 1. Queue theke node ber kore ana
        Bnode* node = q.front();
        q.pop(); 

    // 2. oi node nia kaj
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Create Children nodes
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connection parent node with children node
        node->left = myLeft;
        node->right = myRight;

    // 3. oi node ar children push in queue (thakle)
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }

    return root;
}

void print_level(Bnode* root,int lvl, int x, bool &flag) {
    if(!root) return;

    if(x == lvl) {
        cout << root->val << " "; // root
        flag = true;
    } 
    print_level(root->left, lvl+1, x, flag); // left
    print_level(root->right, lvl+1, x, flag); // right
}

int main() {
    Bnode* root = input_tree();
    int x; cin >> x;

    // Printing
    bool flag  = false;
    print_level(root, 0, x, flag);
    if(!flag) cout << "Invalid";
    cout << endl;

    return 0;
}