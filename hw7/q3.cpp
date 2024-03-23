// Tree Width
// https://xjoi.net/contest/5229/problem/3
/*
Description：
Given a tree with n nodes numbered from 1 to N, among which 1 means the root. Please find out the width of the tree.

Input：
The first line contains a number N (1<=N<=1000).
The next N lines, each line contains N single digit numbers (each could be either 1 or 0). When the i-th row and j-th column is 1, 
it means nodes i and j have an edge. Otherwise, there is no edge. 

Output：
the width of the tree

Sample Input：
10
0110000000
1001000000
1000110001
0100000000
0010000000
0010001000
0000010110
0000001000
0000001000
0010000000

Sample output：
4
*/
// Etaw
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<vector<int>> tree;
  int n;
  map<int, int> widths;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> row;
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == '1') {
        row.push_back(j);
      }
    }
    tree.push_back(row);
  }
  vector<bool> visited(n, false);
  queue<vector<int>> q;
  visited[0] = true;
  widths[0] = 1;
  q.push({0, 0});
  while (!q.empty()) {
    vector<int> curr = q.front();
    if (widths.find(curr[1] + 1) == widths.end()) {
      widths[curr[1] + 1] = 0;
    }
    q.pop();
    for (int i = 0; i < tree[curr[0]].size(); i++) {
      if (visited[tree[curr[0]][i]]) {
        continue;
      }
      visited[tree[curr[0]][i]] = true;
      q.push({tree[curr[0]][i], curr[1] + 1});
      widths[curr[1] + 1]++;
    }
  }
  int ans = 0;
  map<int, int>::iterator it;
  for (it = widths.begin(); it != widths.end(); it++) {
    ans = max(ans, it->second);
    // cout<<it->second<<" ";
  }
  cout << ans;
}