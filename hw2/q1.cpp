// Coin Combinations I
// https://xjoi.net/contest/5037/problem/1
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12839&fragments=31103&problemId=14090
/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of 
distinct ways you can produce a money sum x using the available coins.

For example, if the coins are {2,3,5} and the desired sum is 9, there are 8 ways:
2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output
Print one integer: the number of ways modulo 109+7.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6

Sample Input:
3 9
2 3 5

Sample Output:
8

Hint:
For Coin Combinations I, pay attention to the output requirement: Print one integer: the number of ways modulo 10^9+7.

Some important properties of mod operation:
x % y = (x % y) % y
(x + y) % z = x % z + y % z = (x % z) % z + y % z = (x % z + y) % z

When we sum up numbers and compute (sum % k), instead of keeping a running sum then doing the mod operation, we can actually do mod 
at each step. The remainder will be the same.

    int sum = 0;
    for (i  = 0; i < N; i ++) sum += i;
    sum %= k;

is equivalent to (if there is no intreger overflow):

    int sum = 0;
    for (i  = 0; i < N; i ++) {
      sum += i;
      sum %= k;
    }

The 2nd approach is usually preferred because you have less concern about integer overflow of sum.
*/
// Etaw
// #include <bits/stdc++.h>
// typedef long long ll;
// using namespace std;
 
// int main() {
//   ll n, x; cin>>n>>x;
//   long long mod=pow(10, 9)+7;
//   vector<ll> coins(n);
//   vector<ll> dp(x+1, 0);
//   for (ll i=0; i<n; i++) {
//     cin>>coins[i];
//     if (coins[i]>x) {
//       continue;
//     }
//     dp[coins[i]]=1;
//   }
//   for (ll i=1; i<=x; i++) {
//     for (ll j=0; j<n; j++) {
//       if ((i-coins[j])>=0) {
//         if (dp[i-coins[j]]==0 && ((i-coins[j])!=0)) {
//           continue;
//         }
//         dp[i]+=dp[i-coins[j]];
//         dp[i]%=mod;
//       }
//     }
//   }
//   cout<<dp[x];
// }

// Ev
#include<bits/stdc++.h>
using namespace std;
int n, x;
vector<int> c(101, 0);
vector<int> a(1000001, 0);

int dp(int b){
    for(int i=1; i<=b; i++){
        for(int j=0; j<n; j++){
            if(i-c[j]<0){
                continue;
            }
            a[i]+=a[i-c[j]];
            a[i] %= 1000000007;
        }
        
    }
    return a[b];
}

int main(){
    cin >> n >> x;
    
    for(int i=0; i<n; i++){
        cin >> c[i];
        a[c[i]]=1;
        if(c[i]>x){
            c[i]=0;
        }
        // cout << c[i] << " ";
    }

    cout << dp(x);

}