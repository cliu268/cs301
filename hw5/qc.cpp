// C. Distinct Subsequences
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15256&fragments=45572&problemId=15737
/*
Time limit: 1.00 s  Memory limit: 256 MB
Problem Description:
Given two strings, s and t, count and return the number of occurrences of string t in the subsequences of string s.

Input Format:
The first line contains a string s (1 ≤ s.length ≤ 30) consisting of English letters.
The second line contains a string t (1 ≤ t.length ≤ 30) consisting of English letters.

Output Format:
The number of occurrences of string t in the subsequences of string s.

Example Input:
good
god

Example Output:
2
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    cin >> s >> t;

    int n= s.length();
    int m= t.length();

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i==0){
                dp[0][j]=1; // t(:0) is an empty string, how many occurrences of empty stirng in s's subsequences? always 1
            }
            else if(j==0){
                dp[i][0]=0; // s(:0) is an empty string, how many occurrences of a non-empty string can be found in an empty string? always 0
            }
            else if(t[i-1]==s[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }

    cout << dp[m][n];
}