// Party
// https://xjoi.net/contest/5144/problem/3
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12846&fragments=31105&problemId=1612
/*
There are n types of items. You are given the price and value for each type of items. For each type, you can buy either 0 or s items. 
How to maximize the total value given a total maximum price?

Input：
The first line has two integers n (n <= 500), m (m <= 5000). n represents the total number of types of items ; m represents the 
amount of money you can spend. There are then n lines. Each line has 3 integers: w, v, and s (v<=100,w<=1000,s<=10), representing 
the per-item price, value, and quantity purchased for the type of items (only 0 or s pieces can be purchased).

Output：
Two lines:
First line: A number indicating the maximum value this purchase can have.
The second line: the serial number of the selected item types.

Sample input：
5 1000
80 20 4
40 50 9
30 50 7
40 30 6
20 20 1

Sample output：
1000
2 3 4 5

Time limit：1000
Memory limit：65536
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   int n, m; cin>>n>>m;
//   vector<int> price(n);
//   vector<int> values(n);
//   vector<vector<int>> dp;
//   for (int i=0; i<n; i++) {
//     int x;
//     cin>>price[i]>>values[i]>>x;
//     price[i]*=x;
//     values[i]*=x;
//   }
//   for (int i=0; i<=n; i++) {
//     vector<int> row(m+1, 0);
//     dp.push_back(row);
//   }
//   for (int i=1; i<=n; i++) {
//     for (int j=1; j<=m; j++) {
//       if ((j-price[i-1])<0) {
//         dp[i][j]=dp[i-1][j];
//         continue;
//       }
//       dp[i][j]=max(dp[i-1][j], dp[i-1][j-price[i-1]]+values[i-1]);
//     }
//   }
//   cout<<dp[n][m]<<"\n";
//   vector<int> ans;
//   int x=n; int y=m;
//   while (x>0 && y>0) {
//     if ((dp[x-1][y-price[x-1]]+values[x-1])==dp[x][y] && values[x-1]!=0 && y>=price[x-1]) {
//       ans.push_back(x);
//       y-=price[x-1];
//       x--;
//     }
//     else {
//       x--;
//     }
//   }
//   sort(ans.begin(), ans.end());
//   for (int i : ans) {
//     cout<<i<<" ";
//   }
// }

// Ev
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; //num items, total money
    cin >> n >> m;

    vector<int> weight(n+1, 0);
    vector<int> value(n+1, 0);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++){
        int w, v, s;
        cin >> w >> v >> s;
        weight[i] = w*s;
        value[i] = v*s;
    }

    for(int max_index=1; max_index<=n; max_index++){
        for(int capacity=1; capacity<=m; capacity++){
            if (capacity - weight[max_index] < 0) {
                dp[max_index][capacity] = dp[max_index-1][capacity];
                continue;
            }
            dp[max_index][capacity] = max(dp[max_index-1][capacity], dp[max_index-1][capacity-weight[max_index]] + value[max_index]);
        }
    }

    vector<int> selected;
    int capacity = m;

    for(int i=n; i>=1 && capacity>0; i--){
        if(dp[i][capacity]!= dp[i-1][capacity]){
            selected.push_back(i);
            capacity-=weight[i];
        }
    }

    cout << dp[n][m] << endl;

    sort(selected.begin(), selected.end());

    for(int i=0; i< selected.size(); i++){
        cout << selected[i] << " ";
    }
}