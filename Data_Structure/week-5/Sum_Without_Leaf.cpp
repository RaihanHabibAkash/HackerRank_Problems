/*
You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree except the leaf nodes.

For example:

image

The output for the above tree will be: 60

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output the total sum of that tree except the leaf nodes.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

60
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

    // If there the val is -1 set the root to NULL & return it
    if(val == -1) {
        root = NULL;
        return root;
    }
    else root = new Bnode(val);

    // Queue of nodes
    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
    // 1. Queue theke node ber kora
        Bnode* p = q.front();
        q.pop();

    // 2. oi node nia kaj
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Creating child node based on the input
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connecting nodes with parent node
        p->left = myLeft;
        p->right = myRight;

    // 3. oi node ar children push in the queue(thakle)
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }
    return root;
}

int sum_except_leaf(Bnode* root) {
    // Base case
    if(!root) return 0;

    int l = sum_except_leaf(root->left); // left
    int r = sum_except_leaf(root->right); // right
    
    if(!root->left && !root->right) return l+r; // root
    else return root->val + l + r;
}

int main() {
    Bnode* root = input_tree();
    cout << sum_except_leaf(root) << endl;

    return 0;
}