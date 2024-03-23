// Strategy Games
// https://xjoi.net/contest/5254/problem/2
/*
Description
Bob likes to play computer games, especially strategy games. However, he often cannot pass a game quickly.
Now he has a task to build a castle. The road in the castle forms a tree. He needs to place a minimum number of soldiers on 
the tree's nodes so that the soldiers can be able to watch all the roads. By definition when a soldier is on a node, he can 
watch/observe all nods connected to his own node.
Now please help Bob calculate the minimum number of soldiers he need for a given tree of roads.

Input：
The data in the input file represents a tree of roads, described as follows:
The first line, with a single number N, represents the number of nodes in the tree.
The second to the N+1-th row in the input describe each node information, which is: the node label i, k (there are k edges/nodes 
connected tothe node i); and the next k numbers in the same row are the other nodes (r1, r2, ..., rk) connected to node i.
The node number starts from 0 to n-1 for a tree with n nodes.
Every edge only appears once in the input.

Output：
The output file contains only one number, which is the minimum number of soldiers needed.
For example, for the tree shown in the below figure:
The answer is 1 (all nodes will be seen as long as one soldier is at node 1).

      (0)
       |
      (1)
      / \
    (2) (3)

Sample Input
4
0 1 1
1 2 2 3
2 0
3 0

Sample Output
1

Time limit: 1000ms
Memory Limit: 65536
*/
// Etaw
#include <bits/stdc++.h>
using namespace std;
 
// Total number of soldiers on a tree rooted at an index,
// when no soldier is placed at the index (root).
int dp1[1500];
// Total number of soldiers on a tree rooted at an index,
// when a soldier is placed at the index (root).
int dp2[1500];
vector<vector<int> > child_lists(1500);
 
void dfs(int root) {
  // 301B exercise. Populate dp1[] and dp2[] recursively.
  dp2[root]=1;
  dp1[root]=0;
  for (int i=0; i<child_lists[root].size(); i++) {
    if (dp1[child_lists[root][i]]==-1 || dp2[child_lists[root][i]]==-1) {
      dfs(child_lists[root][i]);
    }
    dp1[root]+=dp2[child_lists[root][i]];
    dp2[root]+=min(dp1[child_lists[root][i]], dp2[child_lists[root][i]]);
  }
  return;
}
 
int main() {
  int N;
  cin >> N;
  int node, child_num, child;
  for (int i = 0; i < N; i++) {
    dp1[i] = -1;
    dp2[i] = -1;
    cin >> node >> child_num;
    for (int j = 0; j < child_num; j++) {
      cin >> child;
      child_lists[node].push_back(child);
    }
  }
 
  // Node 0 is always the root, according to input format.
  dfs(0);
 
  cout << min(dp1[0], dp2[0]) << endl;
}