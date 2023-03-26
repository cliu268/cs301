// Find the ancestor
// https://xjoi.net/contest/5254/problem/3
/*
Description：
Input a tree whose root is 1. You have q inquiries. Given x and k, please find out the k level ancestor of x. 
If there is no such node, print 0.

Input format of the tree: n-1 lines. Each line contains two integers x and y, which is a line connecting x and y. 
It is guaranteed that the input graph is a tree.

Input：
The first line contains two integers n and q. Then input the tree as mentioned in the problem description.
The next q lines each contains two integers x and k, which is a group of inquiry.

Ouput：
q lines. Each line contains an integer, which is the answer.

Sample input 1：
10 5
1 2
1 3
4 2
3 5
6 4
4 7
4 8
8 9
10 5
1 1
6 3
2 2
3 1
4 2

Sample output 1：
0
1
0
1
1

Note： 1<=n，q<=100000
*/