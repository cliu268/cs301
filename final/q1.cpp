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