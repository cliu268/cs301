// A. Edit Distance
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15256&fragments=45572&problemId=14094
/*
Time limit: 1.00 s
Memory limit: 256 MB
The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:
Add one character to the string.
Remove one character from the string.
Replace one character in the string.

For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.
Your task is to calculate the edit distance between two strings.

Input
The first input line has a string that contains n characters between A–Z.
The second input line has a string that contains m characters between A–Z.

Output
Print one integer: the edit distance between the strings.

Constraints: 1≤n,m≤5000

Example Input:
LOVE
MOVIE

Example Output:
2
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;
    int n= a.length();
    int m= b.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0){
                dp[0][j]=j;
            }
            else if(j==0){
                dp[i][0]=i;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
            }
        }
    }

    cout << dp[n][m];
}