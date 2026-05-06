/*
Problem Statement

You will be given an integer array A of size N. You need to print the prefix sum array of the array A in reverse order.

Input Format

First line will contain N.
Next line of contain the array A.
Constraints

1 <= N <= 10^5
1 <= A[i] <= 10^9; Where 0 <= i < N
Output Format

Output the prefix sum array in reverse order.
Sample Input 0

5
2 4 1 5 3
Sample Output 0

15 12 7 6 2 
Explanation 0

The prefix sum of the given array is: 2 6 7 12 15.
The reverse order is: 15 12 7 6 2.
Sample Input 1

3
1000000000 1000000000 1000000000
Sample Output 1

3000000000 2000000000 1000000000 
*/
// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Taking input
    int len; cin >> len;
    vector<int> v(len);
    for(auto it = v.begin(); it < v.end(); it++)
        cin >> *it;

    // Prefix sum
    vector<long long> prefix(len);
    prefix[0] = v[0];
    for(int i = 1; i < len; i++)
        prefix[i] = prefix[i - 1] + v[i];

    // Reversing
    for(int i = 0, j = len - 1; i < j; i++, j--) {
        long long temp = prefix[i];
        prefix[i] = prefix[j];
        prefix[j] = temp;
    }

    for(int i = 0; i < len; i++) cout << prefix[i] << " ";
    cout << endl;

    return 0;
}
