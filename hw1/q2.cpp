// Triangle of Numbers
// https://xjoi.net/contest/5005/problem/2
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12836&fragments=31102&problemId=3657
/*
Digital triangle. Shown below is a number triangle. Please write a script to find out a path somewhere from the top to the bottom, 
so that the sum of the numbers on the path is the largest. Only the sum  is required in the output.
1. Every step can go straight down or right down (diagonal);
2. The number of triangle rows is less than or equal to 100;
3. The numbers in the triangle rows are 0, 1, ..., 99;

The Triangle of Numbers is input line by line through the keyboard. For example, the data should be entered in the following format: 
(in this example, the path should be 7->3->8->7->5 and the sum is 30)
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

Input:
The first line is an integer N to indicate the height of the tower (i.e., the row number of the Trianles of Numbers).
Then followed by N lines, the i-th line has i integers. Each line is a row for the Triangle.

Output:
One integer number.

Sample input:
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

Sample output:
30
*/
// Etaw --> this will TLE for some cases. didn't use DP
// #include <bits/stdc++.h>
// using namespace std;
// int n;
// vector<vector<int>> triangle;
// int maxi=0;
// void solve(int row, int col, int sum) {
//   if (row==(n-1)) {
//     maxi=max(maxi, sum);
//     return;
//   }
//   else {
//     solve(row+1, col, sum+triangle[row+1][col]);
//     solve(row+1, col+1, sum+triangle[row+1][col+1]);
//   }
// }
 
// int main() {
//   cin>>n;
//   for (int i=0; i<n; i++) {
//     vector<int> row;
//     for (int j=0; j<=i; j++) {
//       int x; cin>>x;
//       row.push_back(x);
//     }
//     triangle.push_back(row);
//   }
//   solve(0, 0, triangle[0][0]);
//   cout<<maxi;
// }

// Ev
#include<bits/stdc++.h>
using namespace std;
int n;

vector<vector<int>> t(100, vector<int>(100, 0));
vector<vector<int>> a(100, vector<int>(100, -1));

int dp(int x, int y){
    if(a[x][y] != -1) return a[x][y];
    if(x==n-1){
        a[x][y] = t[x][y];
    }
    else{
        a[x][y] = t[x][y]+max(dp(x+1, y), dp(x+1, y+1));
    }
    return a[x][y];
}

int main(void){
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> t[i][j];
        }
    }

    cout << dp(0, 0);
}