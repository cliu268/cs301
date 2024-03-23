// Choose integers
// https://xjoi.net/contest/5144/problem/2
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12846&fragments=31105&problemId=7151
/*
Description
Choose several numbers from 1 to n，the sum of which should be no more than n. Find out the maximum sum of number of divisors of 
each number.

Sample input
2

Sample output
2

Note: n≤1000
Time and memory limit: 1s，512M
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   int n, W;
//   cin >>n;
//   W=n;
//   int weights[n], values[n];
//   for (int i = 0; i < n; i++) {
//     weights[i]=i+1;
//     int j=2; int n=i+1;
//     values[i]=0;
//     for (int j=1; j<=i+1; j++) {
//       if ((i+1)%j==0) {
//         values[i]++;
//       }
//     }
//   }
 
//   int dp[W + 1];
//   for (int capacity = 0; capacity <= W; capacity++) dp[capacity] = 0;
 
//   for (int max_index = 0; max_index < n; max_index++) {
//     for (int capacity = W; capacity >= weights[max_index]; capacity--) {
//       dp[capacity] = max(dp[capacity],
//                          dp[capacity - weights[max_index]] + values[max_index]);
//     }
//   }
 
//   cout << dp[W];
// }

// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  
    cin >> n;

    vector<int> weight(n+1, 0);
    vector<int> value(n+1, 0);
    vector<int> dp(n+1, 0);

    for(int i=1; i<=n; i++){
        weight[i]=i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(i%j==0){
                value[i]++;
            }
        }
    }

    for(int max_index=0; max_index<=n; max_index++){
        for(int capacity=n; capacity>= weight[max_index]; capacity--){
            dp[capacity] = max(dp[capacity], dp[capacity-weight[max_index]] +value[max_index] );
        }
    }

    cout << dp[n];
}