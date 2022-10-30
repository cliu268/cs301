// Divisible or not
// https://xjoi.net/contest/5167/problem/3
/*
Time: 1s, Memory limits: 512M
Description:
Given N integer numbers（either positive or negative) and a modulus K. You can add either a plus or a minus between two 
adjacent numbers. Thus you will (after calculation) get a sum. If there exists a set of operations (adding plus or minus between 
two numbers) that can make the remainder of the sum and K (namely, MOD(sum,K)) to be 0, then output ‘Divisible’, otherwise output 
‘Not divisible’. For example, given 1 and 3 with a modulus of 4, we could say +1+3=4, and 4 mod 4 = 0 so we would output ‘Divisible’.

Input:
The 1st line: two integers N and K, separated by a space (N<=100，k<=10000)
The 2nd line has n integers numbers (could be positive or negative).

Sample input:
4 7 
17 5 -21 15

Sample output:
Divisible
*/