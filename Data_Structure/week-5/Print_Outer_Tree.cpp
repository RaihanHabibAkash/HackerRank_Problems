/*
You will be given a binary tree as input in level order. You need to print the outer side of the binary tree. See the sample input output for more clarifications. You need to print from the left most leaf node to right most leaf node.

For example:

image

The output for the above tree will be: 90 40 20 10 30 50 60

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output the left most leaf node to right most leaf node.
Sample Input 0

10
20 30
40 70 -1 50
90 110 -1 -1 80 60
-1 -1 -1 -1 100 -1 -1 -1
-1 -1
Sample Output 0

90 40 20 10 30 50 60 
Explanation 0

This test case was explained in the question.
Sample Input 1

10
20 30
-1 40 70 50
60 90 -1 -1 80 -1
-1 -1 -1 -1 100 110
-1 -1 -1 -1
Sample Output 1

60 40 20 10 30 50 80 110 
Explanation 1

Outer part of the binary tree - 
image

Sample Input 2

10
-1 20
-1 50
80 -1
-1 -1
Sample Output 2

10 20 50 80
Explanation 2

Outer part of the binary tree - 
image

Sample Input 3

10
20 -1
-1 50
80 -1
-1 -1
Sample Output 3

80 50 20 10 
Explanation 3

Outer part of the binary tree - 
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
    queue<Bnode*> q;
    q.push(root);

    while(!q.empty()) {
    // 1. Queue theke ber kore ana
        Bnode* node = q.front();
        q.pop();    

    // 2. oi node nia kaj
        int l, r; cin >> l >> r;
        Bnode* myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Bnode(l);
        if(r == -1) myRight = NULL;
        else myRight = new Bnode(r);

        // Connecting parent with child nodes
        node->left = myLeft;
        node->right = myRight;    

    // 3. queue te oi node ar children push(thakle)
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return root;
}

void printing_outer_left(Bnode* root) {
    // Base case
    if(!root) return;

    if(root->left) printing_outer_left(root->left);
    else printing_outer_left(root->right);

    cout << root->val << " ";
}

void printing_outer_right(Bnode* root) {
    // Base caes
    if(!root) return;

    cout << root->val << " ";

    if(root->right) printing_outer_right(root->right);
    else printing_outer_right(root->left);
}

int main() {
    // Taking input
    Bnode* root = input_tree();

    // Taking output
    if(root->left)printing_outer_left(root);
    else cout << root->val << " "; // root will be count
    if(root->right)printing_outer_right(root->right);

    return 0;
}