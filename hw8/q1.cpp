// Subordinates
// https://xjoi.net/contest/5254/problem/1
// https://www.xinyoudui.com/ac/contest/7740019EE0002E10119DCD/problem/14124
/*
Time limit: 1.00 s
Memory limit: 512 MB
Given the structure of a company, your task is to calculate for each employee the number of their subordinates.

Input
The first input line has an integer n: the number of employees. The employees are numbered 1,2,…,n, and employee 1 is the 
general director of the company.
After this, there are n−1 integers: for each employee 2,3,…,n their direct boss in the company.

Output
Print n integers: for each employee 1,2,…,n the number of their subordinates.

Constraints: 1≤n≤2⋅10^5
Example Input:
5
1 1 2 3

Example Output:
4 1 1 0 0
*/
// Etaw
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int> > adjacencies(200001);
vector<int> dp(200001, 1);
 
int dfs(int j) {
  // 301B exercise
  for (int i=0; i<adjacencies[j].size(); i++) {
    dp[j]+=dfs(adjacencies[j][i]);
  }
  return dp[j];
}
 
int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int num;
    cin >> num;
    adjacencies[num].push_back(i);
  }
 
  dfs(1);
 
  for (int i = 1; i <= n; i++) {
    cout << dp[i]-1 << " ";
  }
}

// Ev 80% code
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n; cin >> n;
//     vector<vector<int>> children(n+1);
//     vector<int> answers(n+1, 0);
//     for(int i=0; i<n-1; i++){
//         int a; cin >> a;
//         children[a].push_back(i+2);
//     }

//     queue<int> q;
//     for(int i=1; i<n+1; i++){
//         q.push(i);
//         int ans=-1;
//         while(!q.empty()){
//             int a = q.front();
//             q.pop();
//             ans++;
//             for(int j=0; j<children[a].size(); j++){
//                 q.push(children[a][j]);
//             }
//         }
//         answers[i]=ans;
//     }

//     for(int i=1; i<n+1; i++){
//         cout << answers[i] << " ";
//     }
// }