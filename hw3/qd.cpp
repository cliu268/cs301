// D. Combine the stone piles 2
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15050&fragments=45038&problemId=15699
/*
Time limit：1s   Memory limit：128M

Description：
There are N piles of stones in a circle. The i-th pile of stones weighs Ai. 
Now you have to combine the stones into one pile. You can only combine two adjacent piles. 
The weight of the new pile and the energy it takes both equal to the sum of two piles' weight.

Find out the minimum energy it takes to combine all N piles into one.
 
Input：
The 1st line: a positive integer N（N<=300）--- the number of piles of stones
The 2nd line: N positive integers---the weight of each pile of stones (<=1000)。

Output：
a positive integer--- the minimum energy it takes to combine all N piles into one.

Sample input：
4
1 3 5 2

Sample output：
20

note：
first combine 1&2, and then combine 3&4
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(601, 0);
    vector<int> s(601, 0);
    vector<vector<int>> dp(601, vector<int>(601, 0));

    for(int i=1; i<=n; i++){
        cin >> p[i];
        s[i]=s[i-1]+p[i];
        p[n+i]=p[i];
    }

    for(int i=1; i<n; i++){
        s[n+i]=s[n+i-1]+p[n+i];
    }

    int ans= INT_MAX;

    for(int len=2; len<=n; len++){
        for(int i=1, j=len; j<2*n; i++, j++){
            dp[i][j]=INT_MAX;
            for(int k=i; k<j; k++){
                dp[i][j]=min(dp[i][j], dp[i][k] + dp[k+1][j] + s[j] - s[i-1]);
                if(len==n){
                    ans=min(ans, dp[i][j]);
                }
            }
        }
    }

    cout << ans;

}