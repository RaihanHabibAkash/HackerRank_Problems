/*
You will be given a list  of size . Then you will be given  queries, for each query there will be some commands. Commands are given below -

  -> Insert  into the list. Then print the current minimum value from the list.
 -> Print the current minimum value from the list.
 -> Delete the current minimum value from the list and print the minimum value from the list after deletion.
Note: If the list is empty and you can't print anything then you should print "Empty".

Input Format

First line will contain .
Second line will contain the list  of size .
Third line will contain .
Next  lines will contain the commands.
Constraints

 ; Here  means the values of the list .
Output Format

For each command, print as asked from the list.
Sample Input 0

4
10 -10 -5 -20
10
1
2
2
2
2
0 10
1
2
0 20
1
Sample Output 0

-20
-10
-5
10
Empty
10
10
Empty
20
20
Sample Input 1

6
45 -30 83 -99 19 75 
9
1
2
2
0 32
0 6
2
2
0 -86
1
Sample Output 1

-99
-30
19
19
6
19
32
-86
-86
*/
// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/give-max-min/problem
#include <bits/stdc++.h>
using namespace std;

vector<int> minStack;

void upHeapify() {
    int curIdx = minStack.size()-1;

    while(curIdx > 0) {
        int parIdx = (curIdx-1)/2;
        if(minStack[parIdx] > minStack[curIdx])
            swap(minStack[parIdx], minStack[curIdx]);
        else break;

        curIdx = parIdx;
    }
}

void downHeapify(int index) {
    int parIdx = index;

    while(minStack.size() > 1) {
        int leftIdx = parIdx*2+1,
            rightIdx = parIdx*2+2,
            minIdx = parIdx;

        if(leftIdx < minStack.size() && minStack[minIdx] > minStack[leftIdx])
            minIdx = leftIdx;
        if(rightIdx < minStack.size() && minStack[minIdx] > minStack[rightIdx])
            minIdx = rightIdx;
        
        // If the minIdx was not change means no swap
        if(minIdx == parIdx) break;
        
        swap(minStack[minIdx], minStack[parIdx]);
        parIdx = minIdx;
    }
}

void arrToMinHeap() {
    int lastNonLeafNd = minStack.size()/2-1;
    for(int i = lastNonLeafNd; i >= 0; i--) downHeapify(i);
}

void printMin() {
    if(minStack.empty()) cout << "Empty" << endl;
    else cout << minStack[0] << endl;
}

void dlt() {
    if(minStack.empty()) {
        cout << "Empty" << endl;
        return;
    }
    else if(minStack.size() == 1) {
        minStack.pop_back();
        cout << "Empty" << endl;
        return;
    }

    minStack[0] = minStack[minStack.size()-1];
    minStack.pop_back();

    downHeapify(0);
    printMin();
}

void insert() {
    int val; cin >> val;
    minStack.push_back(val);
    upHeapify();
    printMin();
}

int main() {
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int val; cin >> val;
        minStack.push_back(val);
    }
    arrToMinHeap();
    
    int queries; cin >> queries;
    while(queries--) {
        int x; cin >> x;
        if(x == 0) insert();
        else if(x == 1) printMin();
        else if(x == 2) dlt(); 
    } 

    return 0;
}