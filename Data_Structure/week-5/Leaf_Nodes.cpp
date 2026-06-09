/*
You will be given a binary tree as input in level order. You need to print the values of leaf nodes in descending order.

For example:

image

The output for the above tree will be: 60 50 40

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output the values of leaf nodes in descending order.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

60 50 40
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

    // Queue of nodes
    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
    // 1. queue theke node ber kora
        Bnode* p = q.front();
        q.pop();
    
    // 2. oi node nia kaj
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Creating child nodes
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connection child nodes with parent
        p->left = myLeft;
        p->right = myRight;

    // 3. queue te oi node ar children push(thakle)
        if(p->left) q.push(p->left);
        if(p->right) q.push(p->right);
    }

    return root;
}

void insert_leaf(Bnode* root, vector<int>& v) {
    // Base case
    if(!root) return;

    insert_leaf(root->left, v); // left
    if(!root->left && !root->right) v.push_back(root->val); // root
    insert_leaf(root->right, v); // right
}

int main() {
    // Taking input
    Bnode* root = input_tree();

    // Pusing leaf nodes value in the vector
    vector<int> v;
    insert_leaf(root, v);

    // Sorting in desending
    sort(v.begin(), v.end(), greater<int>());
    
    // Printing
    for(int val : v) cout << val << " ";
    cout << endl;
    
    return 0;
}