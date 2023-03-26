// Palace Guard
// https://xjoi.net/contest/5257/problem/2
/*
There are n buildings in the Summer Palace. Each palace building is identified using an integer ID within the range of 1 to n. 
We need to deploy some guards to guard all these n palace buildings. A guard can guard not only the building where the guard 
is deployed, but also all other buildings within line of sight. For each building, there is a given cost to deploy guards there.

If we use a node to represent a palace building, and we connect two buildings if they are within line of sight of each other, 
we happen to get a tree. That is, there is no cycle.

Input：
Line 1 is an integer n, the total number of palace nodes of the tree.
Line 2 to n+1: each line has the following integers separated by space. The first of these n lines specifies the root of the tree.

the palace node ID i (1 <= i <= n)
the cost to deploy a guard in palace node i
the total number (m) of children of palace node i. Note that node i's parent node does not count.
the IDs of the m child palace nodes. Note that node i's parent node ID is not included.
 
Output：
One integer, the minimum total cost to guard all palace buildings (nodes).

Sample Input：
6
1 30 3 2 3 4
2 16 2 5 6
3 5 0
4 4 0
5 11 0
6 5 0

Sample Output：
25

Data Range：
0 < n <= 1500

Time limit：
1000

Memory limit：
65536 
*/