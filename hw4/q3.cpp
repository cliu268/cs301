// Party
// https://xjoi.net/contest/5144/problem/3
/*
There are n types of items. You are given the price and value for each type of items. For each type, you can buy either 0 or s items. 
How to maximize the total value given a total maximum price?

Input：
The first line has two integers n (n <= 500), m (m <= 5000). n represents the total number of types of items ; m represents the 
amount of money you can spend. There are then n lines. Each line has 3 integers: w, v, and s (v<=100,w<=1000,s<=10), representing 
the per-item price, value, and quantity purchased for the type of items (only 0 or s pieces can be purchased).

Output：
Two lines:
First line: A number indicating the maximum value this purchase can have.
The second line: the serial number of the selected item types.

Sample input：
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1

Sample output：
1000
2 3 4 5

Time limit：1000
Memory limit：65536
*/