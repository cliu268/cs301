// Tree Matching
// https://xjoi.net/contest/5257/problem/1
/*
You are given a tree consisting of n nodes.
A matching is a set of edges where each node is an endpoint of at most one edge. What is the maximum number of edges in a matching?

Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output
Print one integer: the maximum number of pairs.

Constraints
1≤n≤2⋅105
1≤a,b≤n

Sample Input:
5
1 2
1 3
3 4
3 5

Sample Output:
2

Explanation: One possible matching is (1,2) and (3,4).

Hint:
For problem 1 Tree Matching, try to implement the solution for the weighted tree max matching problem we discussed in class 
(instead of just the greedy solution). You can set the weights for all edges the same value, e.g., 1. Check the class slides for 
the state transition formula.
*/