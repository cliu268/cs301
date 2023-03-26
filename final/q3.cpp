// Character issues
// https://xjoi.net/contest/5452/problem/3
/*
Mr. Ba made an important discovery that a person's character can be computed as the maximum sum of the personality indexes of 
the person’s k ancestors. The choice of the set of k ancestors must meet one requirement: if an ancestor is chosen, then all the 
people on the inheritance chain from the chosen ancestor to the person must be chosen. The reason is that the character is inherited, 
and the inheritance chain must be complete. Given the family tree of Mr. Ba, and the personality indexes of his ancestors, please 
calculate his character.

Input：
The first line has two positive integers, n and k, separated by spaces. n is the total number of people in the family tree, 
including Mr.Ba himself. k is the number of ancestors to choose for the character calculation.

The second line has n-1 integers, separated by spaces. The absolute value of these numbers is within 2^15. The i-th number indicates 
the personality index of the person whose ID is i+1. Note that personality index might be negative. Mr. Ba's ID is 1.

Each of the next n lines has two integers, separated by space. The two numbers of the i-th line indicate the IDs of the father and 
mother of the i-th person. If a person's father or mother is not in the family tree, then the ID is 0.

All the data in the input, except Mr. Ba, are the ancestors of Mr. Ba. Every person in the input, except Mr. Ba, has one and only 
one child.

Output：
Mr. Ba's character.

Sample Input：
6 3
-2 3 -2 3 -1
2 3
4 5
0 6
0 0
0 0
0 0

Sample Output：
4

Data Range：
For 50% of the data, n<=10;
For 100% of the data, n<=100.

Time limit：1000
Memory limit：10240
*/