// Minimizing Coins
// https://xjoi.net/contest/5005/problem/1
/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x 
using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6

Sample Input:
3 11
1 5 7

Sample Output:
3

Hint:
For Minimizing Coins, to pass all tests you might need to implement the iterative solution.
- That is, starting from the smallest subproblems (when x = 0, dp[0] = 0), use the state transition 
  dp[x] = min(1+dp[x-coin_values[0]], 1+dp[x-coin_values[1], ...) to sequentially compute the solution with increasing x, 
  until you finally reach the solution to the target x given in the problem statement.
- Recursive solution with memoization might still fail one test for timeout.
And, do not forget implementing the last sentence of the problem statement: 
"If it is not possible to produce the desired sum, print −1."
*/