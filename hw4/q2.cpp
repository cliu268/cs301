// Choose integers
// https://xjoi.net/contest/5144/problem/2
/*
Description
Choose several numbers from 1 to n，the sum of which should be no more than n. Find out the maximum sum of number of divisors of 
each number.

Sample input
2

Sample output
2

Note: n≤1000
Time and memory limit: 1s，512M
*/
#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, W;
  cin >>n;
  W=n;
  int weights[n], values[n];
  for (int i = 0; i < n; i++) {
    weights[i]=i+1;
    int j=2; int n=i+1;
    values[i]=0;
    for (int j=1; j<=i+1; j++) {
      if ((i+1)%j==0) {
        values[i]++;
      }
    }
  }
 
  int dp[W + 1];
  for (int capacity = 0; capacity <= W; capacity++) dp[capacity] = 0;
 
  for (int max_index = 0; max_index < n; max_index++) {
    for (int capacity = W; capacity >= weights[max_index]; capacity--) {
      dp[capacity] = max(dp[capacity],
                         dp[capacity - weights[max_index]] + values[max_index]);
    }
  }
 
  cout << dp[W];
}