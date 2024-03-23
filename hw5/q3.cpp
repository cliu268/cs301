// Divisible or not
// https://xjoi.net/contest/5167/problem/3
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12849&fragments=31106&problemId=7154
/*
Time: 1s, Memory limits: 512M
Description:
Given N integer numbers（either positive or negative) and a modulus K. You can add either a plus or a minus between two 
adjacent numbers. Thus you will (after calculation) get a sum. If there exists a set of operations (adding plus or minus between 
two numbers) that can make the remainder of the sum and K (namely, MOD(sum,K)) to be 0, then output ‘Divisible’, otherwise output 
‘Not divisible’. For example, given 1 and 3 with a modulus of 4, we could say +1+3=4, and 4 mod 4 = 0 so we would output ‘Divisible’.

Input:
The 1st line: two integers N and K, separated by a space (N<=100，k<=10000)
The 2nd line has n integers numbers (could be positive or negative).

Sample input:
4 7 
17 5 -21 15

Sample output:
Divisible
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int mod(int x, int y) {
//   x%=y;
//   if (x<0) {
//     return y+x;
//   }
//   else {
//     return x;
//   }
// }
// int main() {
//   int n, k; cin>>n>>k;
//   vector<int> number(n);
//   for (int i=0; i<n; i++) {
//     cin>>number[i];
//     // number[i]=mod(number[i], k);
//   }
//   int dp[n][k]; memset(dp, 0, sizeof dp);
//   dp[0][mod(number[0], k)]=1;
//   for (int i=1; i<n; i++) {
//     for (int j=0; j<k; j++) {
//       if (dp[i-1][j]==1) {
//         dp[i][mod(j+number[i], k)]=1;
//         dp[i][mod(j-number[i], k)]=1;
//       }
//     }
//   }
//   if (dp[n-1][0]==1) {
//     cout<<"Divisible";
//   }
//   else {
//     cout<<"Not divisible";
//   }
// }

// Ev
#include<bits/stdc++.h>
using namespace std;

int mod(int x, int y){
    x%=y;
    if(x<0){
        x+=y;
    }
    return x;
}

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<bool>> dp(n, vector<bool>(k, 0));
    vector<int> values(n, 0);

    for(int i=0; i<n; i++){
        cin >> values[i];
        //values[i] = mod(values[i], k);
    }

    dp[0][mod(values[0], k)] = true;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<k; j++){
            if(dp[i][j]){
                dp[i+1][mod(j+values[i+1], k)] = true;
                dp[i+1][mod(j-values[i+1], k)] = true;
            }
        }
    }

    if(dp[n-1][0]==true){
        cout << "Divisible";
    }
    else{
        cout << "Not divisible";
    }
}