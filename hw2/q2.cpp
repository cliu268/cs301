// the longest common subsequence
// https://xjoi.net/contest/5037/problem/2
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15233&fragments=45308&problemId=3587
/*
Find the longest common subsequence of the two strings given.

For the string abcde
acd, ace, ade, etc. are all its subsequences. But acb is not.

Input :
two lines, each containing a string

Output :
an integer representing the length of the longest common subsequence

Sample input 1:
xjoixjoi
joyjoy

Sample output 1:
4

Sample input 2:
xsrrnzkbhzkhzmvkjevsrbdiclckmsgpgngyckzvgysvwcgwayjokqactfxtivfbdwprufivtgg 
zhbpvlxfkisdneogdseenjlewrobjhpppjczyxeaiqanaztksnpfwyhdjvipgwzznmnnxwraiiei

Sample output 2:
21

Note:
string length should be less than or equal to 1000.
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   string s1, s2; cin>>s1>>s2;
//   vector<vector<int>> dp;
//   for (int i=0; i<=s1.length(); i++) {
//     vector<int> row(s2.length()+1, 0);
//     dp.push_back(row);
//   }
//   for (int i=1; i<=s1.length(); i++) {
//     for (int j=1; j<=s2.length(); j++) {
//       if (s1[i-1]==s2[j-1]) {
//         dp[i][j]=1+dp[i-1][j-1];
//       }
//       else {
//         dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
//       }
//     }
//   }
//   cout<<dp[s1.length()][s2.length()];
// }

// Ev
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp(1000, vector<int>(1000, 0));

int lcs(string x, string y, int e, int f){
    for(int i=0; i<=e; i++){
        for(int j=0; j<=f; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                dp[i][j]= dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[e][f];
}

int main(){
    string a, b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();    

    cout << lcs(a, b, n, m);
}