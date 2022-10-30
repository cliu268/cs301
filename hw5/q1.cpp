// Backpack Groups
// https://xjoi.net/contest/5167/problem/1
/*
Time Limit: 1s Memory Limit: 128M
Description:
A traveler has a backpack whose maximum capacity is V kilograms. There are now n items whose weights are W1, W2, ..., Wn, and 
their values are C1, C2, ..., Cn. These items are divided into several groups, and the items in each group conflict with each 
other, and at most one item can be selected. Solving which items are loaded into the backpack that allow the sum of these items 
not to exceed the backpack capacity, and the sum of the values is the largest.

Input:
Line 1: three integers, V (package capacity, V <= 200), N (number of items, N <= 30) and T (maximum group number, T <= 10);
Line 2..N+1: Three integers Wi, Ci, P per line, indicating the weight, value, and group number of each item.

Output:
Only one line, one number, represents the maximum total value.

Sample input:
10 6 3 
2 1 1 
3 3 1 
4 8 2 
6 9 2 
2 8 3 
3 9 3

Sample output:
20
*/