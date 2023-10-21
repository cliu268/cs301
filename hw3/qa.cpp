// A. Combine the stone piles
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15050&fragments=45038&problemId=7186
/*
Time limit：1s   Memory limit：128M

Description：
There are N piles of stones in a line. The i-th pile of stones weighs Ai
​Now you have to combine the stones into one pile. You can only combine two adjacent piles. 
The weight of the new pile and the energy it costs equal to the sum of two piles' weight.

Find out the minimum energy it costs to combine all N piles into one.
 
Input：
The 1st line: a positive integer N（N<=300）--- the number of piles of stones
The 2nd line: N positive integers---the weight of each pile of stones (<=1000)。

Output：
a positive integer--- the minimum energy it costs to combine all N piles into one.

Sample input：
4
1 3 5 2

Sample output：
22

note：
first combine 1&2, and then combine 3&4
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> p(301, 0);
vector<vector<int>> dp(301, vector<int>(301, 0));
vector<int> s(301, 0);

int main(){
    cin >> n;

    for(int i=1; i<n+1; i++){
        cin >> p[i];
        s[i]=s[i-1]+p[i];
    }

    for(int len=2; len<=n; len++){
        for(int i=1, j=len; j<=n; i++, j++){
            dp[i][j]=INT_MAX;
            for(int k=i; k<j; k++){
                dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j] + s[j] - s[i-1]);
            }
        }
    }

    cout << dp[1][n] << endl;
}