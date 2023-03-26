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