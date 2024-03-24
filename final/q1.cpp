// A party without boss
// https://xjoi.net/contest/5452/problem/1
/*
A college has N employees, numbered from 1 to N. Their reporting relationship forms a tree, in which the principal is the root of 
the tree, and each parent node is the direct manager of the children node. There is a annual party which invites every employee. 
Every participating employee will bring a happy index of Ri to the party. However, if an employee's direct manager is in the party, 
then the employee would not come to party. Your task is to which employees to invite such that the sum of the happy index is maximized.

Input:
First line one number N。(1<=N<=100000)
Next N line，the i+1 line represent employee i's happy index Ri。(-128<=Ri<=127)
Next N-1line，each line has a pair of numbers, L,K, where K is L's direct manager。

Output:
The maximum happy index of the party.

sample input 1：
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5

sample output 1：
5

note: 1<=n<=100000
*/
// Etaw
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> happy(1e5+1);
vector<int> parent(1e5+1, -1);
vector<vector<int>> child(1e5+1);
vector<int> dp1(1e5+1, -1);
vector<int> dp2(1e5+1, -1);
void dfs(int x) {
  dp1[x]=happy[x];
  dp2[x]=0;
  for (int i=0; i<child[x].size(); i++) {
    int k=child[x][i];
    if (dp1[k]==-1 || dp2[k]==-1) {
      dfs(k);
    }
    dp1[x]+=dp2[k];
    dp2[x]+=max(dp2[k], dp1[k]);
  }
}
int main() {
  cin>>n;
  for (int i=1; i<=n; i++) {
    cin>>happy[i];
  }
  for (int j=0; j<n-1; j++) {
    int l, k; cin>>l>>k;
    child[k].push_back(l);
    parent[l]=k;
  }
  int root;
  for (int i=1; i<=n; i++) {
    if (parent[i]==-1) {
      root=i;
      break;
    }
  }
  dfs(root);
  cout<<max(dp1[root], dp2[root]);
}