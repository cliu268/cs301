// Money Sums
// https://xjoi.net/contest/5144/problem/1
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12846&fragments=31105&problemId=14187
/*
Time limit: 1.00 s
Memory limit: 512 MB
You have n coins with certain values. Your task is to find all money sums you can create using these coins.

Input
The first input line has an integer n: the number of coins.
The next line has n integers x1,x2,…,xn: the values of the coins.

Output
First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.

Constraints: 1≤n≤100, 1≤xi≤1000

Example
Input:
4
4 2 5 2

Output:
9
2 4 5 6 7 8 9 11 13
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   int n;
//   cin >> n;
 
//   int weights[n];
//   int W=0;
//   for (int i = 0; i < n; i++) {
//     cin >> weights[i];
//     W+=weights[i];
//   }
 
//   int dp[W + 1];
//   for (int capacity = 0; capacity <= W; capacity++) dp[capacity] = 0;
   
//   for (int max_index = 0; max_index < n; max_index++) {
//     for (int capacity = W; capacity >= weights[max_index]; capacity--) {
//       dp[capacity] = max(dp[capacity],
//                          dp[capacity - weights[max_index]] + weights[max_index]);
//     }
//   }
//   map<int, bool> visited;
//   int count=0;
//   for (int i=0; i<=W; i++) {
//     if (dp[i]>0 && !visited[dp[i]]) {
//       visited[dp[i]]=true;
//       count++;
//     }
//   }
//   cout<<count<<"\n";
//   map<int, bool> visited2;
//   for (int i=0; i<=W; i++) {
//     if (dp[i]>0 && !visited2[dp[i]]) {
//       visited2[dp[i]]=true;
//       cout<<dp[i]<<" ";
//     }
//   }
// }

// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    vector<int> weight(n+1, 0);
    

    int sum=0;

    for(int i=0; i<n; i++){
        cin >> weight[i];
        sum+=weight[i];
    }
    
    vector<bool> dp(sum+1, false);
    dp[0] = true;

    for(int max_index=0; max_index<n; max_index++){
        for(int capacity=sum; capacity>=weight[max_index]; capacity--){
            dp[capacity] = dp[capacity] || dp[capacity - weight[max_index]];
        }
    }

    int ans=0;
    vector<int> vals;

    for(int i=1; i<=sum; i++){
        if(dp[i]==1){
            ans++;
            vals.push_back(i);
        }
    }

    cout << ans << " ";

    for(int i=0; i<vals.size(); i++){
        cout << vals[i] << " ";
    }
}