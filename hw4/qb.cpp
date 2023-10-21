// B. Interleaving String
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15233&fragments=45308&problemId=15628
/*
Time limit: 1s   Memory limit: 512M

Description :
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Input :
Three lines, each containing a string.
s1, s2, s3. (0 ≤ s1.length, s2.length ≤ 100,  0 ≤ s3.length ≤ 200)

Output :
"yes" or "no".

Sample input 1:
abc
xby
axbbyc

Sample output 1:
yes

Sample input 2:
abc
xby
abbxyc

Sample output 2:
no
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 && j==0){
                dp[i][j] = 1;
            }
            else if(j==0){
                if(s3[i-1] == s1[i-1]){
                    dp[i][0] = dp[i-1][0];
                }
                else {
                    dp[i][0] = 0;
                }
            }
            else if(i==0){
                if(s3[j-1] == s2[j-1]){
                    dp[0][j] = dp[0][j-1];
                }
                else{
                    dp[0][j] = 0;
                }
            }
            else{
                dp[i][j] = (s3[i+j-1] == s1[i-1] && dp[i-1][j]) || (s3[i+j-1] == s2[j-1] && dp[i][j-1]);
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