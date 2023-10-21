// C. Wildcard Matching
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15233&fragments=45308&problemId=15781
/*
Time Limit: 1s    Memeory Limit: 512M

Description:
Given an string s and a pattern p, implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Input :
The first line contines a string s.
The second line contines a string p.
0 ≤ s.length, p.length ≤ 2000.
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

Output :
"yes" or "no".

Sample input 1:
app
ap

Sample output 1:
no

Sample input 2:
app
a?p

Sample output 2:
yes

Sample input 3:
abc
a*

Sample output 3:
yes

Sample input 4:
abc
?a*

Sample output 4:
no
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, p;
    cin >> s >> p;

    int n = s.length();
    int m = p.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
            }
            else if(j==0){
                dp[i][0] = 0;
            }
            else if(i==0){
                if(p[j-1] == '*'){
                    dp[0][j] = dp[0][j-1];
                }
                else{
                    dp[0][j] = 0;
                }
            }
            else{
                if(p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if (p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else { // patter is a letter
                    dp[i][j] = (s[i-1] == p[j-1]) && dp[i-1][j-1];
                }
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    if(dp[n][m]==0){
        cout << "no";
    }
    else{
        cout << "yes";
    }
}
