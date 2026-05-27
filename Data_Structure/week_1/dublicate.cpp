/*
Problem Statement

You will be given an array A of size N. Print "YES" if there is any duplicate value in the array, "NO" otherwise.

Input Format

First line will contain N.
Second line will contain the array A.
Constraints

1 <= N <= 100000
0 <= A[i] <= 10^9; Where 0 <= i < N
Output Format

Output "YES" or "NO" without the quotation marks according to the problem statement.
Sample Input 0

5
1 2 3 4 5
Sample Output 0

NO
Sample Input 1

6
2 1 3 5 2 1 
Sample Output 1

YES
*/
// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges
#include <bits/stdc++.h>
using namespace std;

int main() {
    int len; cin >> len;
    vector<int> v(len);
    for(auto it = v.begin(); it < v.end(); it++) 
        cin >> *it;

    // Sorting
    sort(v.begin(), v.end());
    
    // Searching O(n logn)
    bool flag = false;
    for(int i = 1; i < len; i++) {
        if(v[i - 1] == v[i]) { flag = true; break; }
    // For ends
    }

    // Printing
    cout << (flag ? "YES" : "NO") << endl;

    return 0;
}
