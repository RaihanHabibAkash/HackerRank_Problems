/*
You will be given a binary tree as input in level order. You need to tell if the binary tree is perfect or not. A binary tree is called perfect if all leaf nodes are at the maximum depth of the tree, and the tree is completely filled with no gaps.

Here is an example of perfect binary tree:

image

Also there is formula available to tell if a binary tree is perfect or not. The formula is :

Total number of nodes = -1
Note: Here depth is counted from . In the above image maximum depth is , so total number of nodes are . So there should be  nodes to call it a perfect binary tree.

Image Source: OpenGenus Iq

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output  if the tree is perfect,  otherwise.
Sample Input 0

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 0

YES
Sample Input 1

10 20 30 40 -1 60 -1 -1 -1 -1 -1
Sample Output 1

NO
Sample Input 2

10 20 -1 -1 -1
Sample Output 2

NO
Sample Input 3

10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 3

YES
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
int maxDepth = 0, nodes = 0;

Bnode* input_tree() {
    int val; cin >> val;
    Bnode* root;

    // Create root based on input
    if(val == -1) {
        root = NULL;
        return root;
    }
    else root = new Bnode(val);

    // Creating queue of pairs, pairs of nodes & int levels
    queue<pair<Bnode*, int>> q;
    q.push({root, 1});

    while(!q.empty()) {
    // 1. queue theke ber kore ana
        Bnode* node = q.front().first;
        int level = q.front().second;
        q.pop();
        
        nodes++;
        if(maxDepth != level) maxDepth = level;    

    // 2. oi node nia kaj

        // Taking inputs
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;

        // Creating nodes based on inputs
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connection
        node->left = myLeft;
        node->right = myRight;

    // 3. queue te oi node ar children push thakle
        if(node->left) q.push({node->left, level+1});
        if(node->right) q.push({node->right, level+1});
    }

    return root;
}

int main() {
    Bnode* root = input_tree();

    if(pow(2, maxDepth)-1 == nodes) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}