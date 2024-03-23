// Tree Depth
// https://xjoi.net/contest/5229/problem/2 
/*
Description：
Given a tree with N nodes numbered from 1 to N, among which 1 is the number for the root. Please find out the depth of the tree.

Input：
The first line contains a number N. （1<=N<=1000）
In the next N lines, each line contains N single-digit numbers (each could be 1 or 0 only). When the value at j-th column and 
i-th row is 1, it means node i and j have an edge in between. Otherwise, there is no edge. 

Output：
The depth of the tree.

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

Sample Output：
4
*/
// Etaw
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> tree;
int n;
int ans=0;
void dfs(int x, int depth, vector<bool> &visited) {
  visited[x]=true;
  bool found=false;
  for (int i=0; i<tree[x].size(); i++) {
    if (visited[tree[x][i]]) {
      continue;
    }
    found=true;
    dfs(tree[x][i], depth+1, visited);
  }
  visited[x]=false;
  if (!found) {
    ans=max(ans, depth);
    cout<<"\n";
    return;
  }
}
int main() {
  cin>>n;
 
  for (int i=0; i<n; i++) {
    vector<int> row;
    for (int j=0; j<n; j++) {
      char c; cin>>c;
      if (c=='1') {
        row.push_back(j);
      }
    }
    tree.push_back(row);
  }
  vector<bool> visited(n, false);
  dfs(0, 1, visited);
  cout<<ans-1;
}