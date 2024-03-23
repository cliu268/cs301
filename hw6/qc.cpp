// C. Skiing
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15481&fragments=46926&problemId=1606
// DFS version of this problem is found in cs201 hw6a q3.cpp and hw7 q1.cpp
/*
Time Limit: 1000ms  Memory Limit: 65536kB
Description
You are given a ski area that is represented by a two-dimensional array. The row and column of an array cell represent the location 
(i.e., the x and y coordinates). The cell content is the height at the location. Please find the longest landslide in this ski area.

Below is an example:
1   2   3   4   5
16  17  18  19  6
15  24  25  20  7
14  23  22  21  8
13  12  11  10  9

One can ski from one point to one of the four adjacent points (in up, down, left, and right directions) if and only if the height decreases. 
In the above example, a skiiable landslide is 24-17-16-1. Another landslide 25-24-23-...-3-2-1 is longer. In fact, it is the longest landslide.

Input
The first two numbers, R, C, indicate the number of rows and columns in the ski area (1≤R, C≤100). The following is R row, each row has 
C integers, indicating the height H (0 ≤ H ≤ 10000).

Output
Include a row that contains only an integer that indicates the length of the longest landslide in the ski area.

Sample Input
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

Sample Output
25
*/
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int r, c;
    cin >> r >> c;

    vector<vector<int>> ski(r, vector<int>(c, 0));
    vector<vector<int>> dp(r, vector<int>(c, 0));

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> ski[i][j];
        }
    }
 

 
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                dp[i][j]= maze[i][j];
            }
            else if(i==0){
                dp[i][j]= dp[i][j-1] + maze[i][j];
            }
            else if(j==0){
                dp[i][j]= dp[i-1][j] + maze[i][j];
            }
            else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]) + maze[i][j];
            }
        }
    }

    cout << dp[n-1][n-1] << endl;
    return 0;
}