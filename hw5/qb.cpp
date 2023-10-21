// B. Edit Distance2
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15256&fragments=45572&problemId=15746
/*
Time limit: 1.00 s  Memory limit: 256 MB
Edit a source string into a target string. And different operations have different costs.

The allowed operations and costs are:
Add one character to the string, cost x;
Remove one character from the string, cost y;
Replace one character in the string, cost z;

Your task is to calculate the minimum edit cost between two strings.

Input
The first input line contains a,b,c; (1 ≤ a,b,c ≤ 9)
The second input line has a string that contains n characters between A–Z.
The third input line has a string that contains m characters between A–Z.

Output
Print one integer: the minimum edit cost between the strings.

Constraints:
1 ≤ n,m ≤ 5000

Example Input:
1 2 3
LOVE
MOVIE

Example Output:
4
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    string a, b;
    cin >> a >> b;
    int n= a.length();
    int m= b.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0){
                dp[0][j]=j*x; // transform empty string into string of length j
            }
            else if(j==0){
                dp[i][0]=i*y; // transform a string of length i into an empty string
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(min(dp[i-1][j]+y, dp[i-1][j-1]+z), dp[i][j-1]+x);
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }    

    cout << dp[n][m];
}