// https://cses.fi/problemset/task/1638
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int dp[1001][1001];
int main(void) {
    int n; cin>>n;
    string grid[1001];
    for (int i=0; i<n; i++) {
        cin >> grid[i];
    }
    memset(dp, 0, sizeof dp);
    if (grid[0][0] == '*') dp[0][0] = 0;
    else dp[0][0]=1;
    for (int i=1; i<n; i++) {
        if (grid[0][i]=='*') {
            dp[0][i] = 0;
        } else {
            dp[0][i] = dp[0][i-1];
        }
        if (grid[i][0]=='*') {
            dp[i][0]=0;
        } else {
            dp[i][0]=dp[i-1][0];
        }
    }    
    for (int i=1; i<n; i++) {
        for (int j=1; j<n; j++) {
            if (grid[i][j]=='*') {
                dp[i][j]=0;
            }
            else {
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            dp[i][j]%=1000000007;
            //cout << "dp[" << i << "][" << j << "] " << dp[i][j] << '\n';
        }
    }
    //cout << "n is " << n << " and answer is " << dp[n-1][n-1];
    cout << dp[n-1][n-1];
    return 0;
}