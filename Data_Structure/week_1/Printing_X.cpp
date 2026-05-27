/*Problem Statement

You will be given an positive odd integer N, you need to print the pattern for it. See sample input and output for understanding the pattern.

Input Format

Input will contain only N.
Constraints

1 <= N <= 20 and N is odd.
Output Format

Output the pattern.
Sample Input 0

5
Sample Output 0

\   /
 \ / 
  X  
 / \ 
/   \
Sample Input 1

7
Sample Output 1

\     /
 \   / 
  \ /  
   X   
  / \  
 /   \ 
/     \
Sample Input 2

3
Sample Output 2

\ /
 X 
/ \
Sample Input 3

1
Sample Output 3

X
*/
// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges

#include <bits/stdc++.h>
using namespace std;

int main() {
    int len; cin >> len;
    int arr[len][len];

    // Printing
    int middle = len / 2;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            if(i == j) {
                if(i == middle && j == middle) cout << "X";
                else cout << '\\';
            }
            else if((len - 1) == i + j) cout << '/';
            else cout << " ";
            
        }
        cout << endl;
    }

    return 0;
}