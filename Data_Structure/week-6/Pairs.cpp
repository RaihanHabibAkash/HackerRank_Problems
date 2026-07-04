/*
You will be given a list  of type pairs. Each pair will contain one string  and one unique integer . The string will contain only English lowercase alphabets and no spaces.

You need to sort the pairs according to the string values in ascending order. If there are multiple pairs with the same string, you need to sort them according to the integer value in descending order.

Input Format

First line will contain , the size of the list .
Next  lines will contain pairs of string  and integer .
Constraints

Output Format

Output the final list after sorting according to the question.
Sample Input 0

5
sakib 1
rakib 2
tasfia 3
asfia 4
afia 5
Sample Output 0

afia 5
asfia 4
rakib 2
sakib 1
tasfia 3
Sample Input 1

6
sakib 5
rakib 3
tasfia 2
sakib 6
afia 1
sakib 4
Sample Output 1

afia 1
rakib 3
sakib 6
sakib 5
sakib 4
tasfia 2
*/
// https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-06/challenges/pairs-17/problem
#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator()(pair<string,int> l, pair<string,int> r) {
        if(l.first == r.first) return l.second < r.second;
        else return l.first > r.first;
    }
};

int main() {
    int cs; cin >> cs;
    priority_queue<pair<string,int>, vector<pair<string,int>>, cmp> pq;

    while(cs--) {
        string s; int val; cin >> s >> val;
        pq.push({s, val});
    }

    while(!pq.empty()) {
        cout << pq.top().first << " " << pq.top().second << endl;
        pq.pop();
    }

    return 0;
}