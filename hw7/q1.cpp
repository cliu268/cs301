// Job Selection
// https://xjoi.net/contest/5229/problem/1
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15481&fragments=46926&problemId=9980
/*
We have n jobs, where every job is scheduled to be done from startTimei to endTimei, obtaining a profit of profiti.

You're given the startTime, endTime and profit arrays. You need to select some of the jobs to finish. Please find the maximum 
profit you can take such that there are no two selected jobs with overlapping time range.

Note that if you choose a job that ends at time X, you will be able to start another job that starts at time X.

Input
The first line contains an integer n, the number of jobs.
For the following n lines, each line contains 3 integers, startTimei, endTimei and profiti.

Output
An integer, the maximum profit you can take.

Sample Input
5
8 10 5
3 6 8
1 9 1
5 10 8
6 7 4

Sample Output
17

Constraint
1≤n≤1000, 1≤startTimei<endTimei≤1000, 1≤profiti≤1000.
*/
// Etaw
#include <bits/stdc++.h>
using namespace std;
 
bool sortbyend(const vector<int> &a, const vector<int> &b) {
  if (a[1]==b[1]) {
    return a[0]<b[0];
  }
  return a[1]<b[1];
}
int main() {
  int n; cin>>n;
  vector<vector<int>> jobs;
  jobs.push_back({0, 0, 0});
  vector<int> end;
  for (int i=0; i<n; i++) {
    int a, b, c; cin>>a>>b>>c;
    jobs.push_back({a, b, c});
  }
  sort(jobs.begin(), jobs.end(), sortbyend);
  for (int i=0; i<=n; i++) {
    end.push_back(jobs[i][1]);
    // cout<<end[i]<<"\n";
  }
  int dp[n+1]; dp[0]=0;
  int p[n+1]; p[0]=0;
  for (int i=1; i<=n; i++) {
    p[i]=upper_bound(end.begin(), end.end(), jobs[i][0])-end.begin()-1;
    if (p[i]<0) {
      p[i]=0;
    }
    if (p[i]>=i) {
      p[i]=0;
    }
    // cout<<p[i]<<" ";
  }
  // for (int i=0; i<=n; i++) {
  //   cout<<jobs[i][0]<<" "<<jobs[i][1]<<" "<<jobs[i][2]<<"\n";
  // }
  for (int i=1; i<=n; i++) {
    dp[i]=max(dp[i-1], dp[p[i]]+jobs[i][2]);
  }
  cout<<dp[n];
}