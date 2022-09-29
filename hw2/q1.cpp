// Coin Combinations I
// https://xjoi.net/contest/5037/problem/1
/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of 
distinct ways you can produce a money sum x using the available coins.

For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output
Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6

Sample Input:
3 9
2 3 5

Sample Output:
8

Hint:
For Coin Combinations I, pay attention to the output requirement: Print one integer: the number of ways modulo 10^9+7.

Some important properties of mod operation:
x % y = (x % y) % y
(x + y) % z = x % z + y % z = (x % z) % z + y % z = (x % z + y) % z

When we sum up numbers and compute (sum % k), instead of keeping a running sum then doing the mod operation, we can actually do mod 
at each step. The remainder will be the same.

    int sum = 0;
    for (i  = 0; i < N; i ++) sum += i;
    sum %= k;

is equivalent to (if there is no intreger overflow):

    int sum = 0;
    for (i  = 0; i < N; i ++) {
      sum += i;
      sum %= k;
    }

The 2nd approach is usually preferred because you have less concern about integer overflow of sum.
*/