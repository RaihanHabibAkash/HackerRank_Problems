/*
You will be given a list  of size . You need to sort those values in ascending order and also you need to remove any duplicate values from the list and print the final outcome.

Input Format

First line will contain , the number of test cases.
The first line of every test case will contain .
The second line of every test case will contain the list  of size .
Constraints

, Here 
Output Format

Output the final list.
Sample Input 0

6
8
3 10 0 6 9 5 10 10 
2
7 3 
6
7 8 2 0 6 3 
4
6 2 0 1 
10
10 0 7 8 5 3 0 3 0 4 
9
9 3 7 10 6 9 0 6 3 
Sample Output 0

0 3 5 6 9 10 
3 7 
0 2 3 6 7 8 
0 1 2 6 
0 3 4 5 7 8 10 
0 3 6 7 9 10 
*/
// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/sorted-3-1/problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    int cs; cin >> cs;

    while(cs--) {
        set<int> st;
        int n; cin >> n;

        while(n--) {
            int val; cin >> val;
            st.insert(val);
        }

        for(int val : st) cout << val << " ";
        cout << endl;
    }

    return 0;
}