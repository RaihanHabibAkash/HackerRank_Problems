/*
Problem Statement

You will given an integer array A of size N and another array B of size M. Also you will be given an index X. You need to insert the whole array B to the index X of array A.

Input Format

First line will contain N.
Second line will contain array A.
Third line will contain M.
Fourth line will contain array B.
The last line will contain X.
Constraints

1 <= N, M <= 10^3
1 <= A[i], B[j] <= 10^3; Where 0 <= i < N and 0 <= j < M
0 <= X <= N
Output Format

Output the final array A.
Sample Input 0

5
2 3 4 5 6
3
10 20 30
3
Sample Output 0

2 3 4 10 20 30 5 6 
Sample Input 1

5
2 3 4 5 6
3
10 20 30
0
Sample Output 1

10 20 30 2 3 4 5 6 
Sample Input 2

4
3 4 5 6
3
10 20 30
4
Sample Output 2

3 4 5 6 10 20 30 
*/
// https://www.hackerrank.com/contests/assignment-01-a-basic-data-structure-a-batch-06/challenges
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Takking first array
    int len1; cin >> len1;
    vector<int> v1(len1);
    for(auto it = v1.begin(); it < v1.end(); it++)
        cin >> *it;

    // Taking second array
    int len2; cin >> len2;
    vector<int> v2(len2);
    for(auto it = v2.begin(); it < v2.end(); it++)
        cin >> *it;
    
    // Taking target index
    int index; cin >> index;

    // Taking from v1 for index
    int cnt = 0;
    for(int i = 0; i < index; i++) {
        cout << v1[i] << " ";
        cnt++;
    }

    // For v2
    for(auto it = v2.begin(); it < v2.end(); it++)
        cout << *it << " ";
    
    // For left v1
    if(!v1.empty()) {
        for(int i = cnt; i < v1.size(); i++)
            cout << v1[i] << " ";
    }

    cout << endl;

    return 0;
}