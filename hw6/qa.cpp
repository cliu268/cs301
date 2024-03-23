// A. Taking numbers in cells
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15481&fragments=46926&problemId=7180
/*
Time limit：1s   Memory limit：256M
Description：
In an N*N table (N<=1000), there are positive integers in some of the cells and 0s in the rest. Only going down and right, Jimmy starts 
at point A (1,1) in the upper left and wants to reach point B (N, N) in the bottom right through the path that maximizes the sum of the 
values of the numbers along the way. Help Jimmy maximize the sum of the numbers along a path from the top left to the bottom right.

Input：
The first line contains an integer N（N≤1000），representing size of the table (N×N).
Each following line contains three integers-- the number of the row and the column, and the number inside that cell.  
“0 0 0” in a line means the end of the input.

Output：
an integer, which represents the maximum sum of numbers on a path from A to B.

Sample input：
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0

Sample output：
36

Sample input 1:
5
3 3 5
2 2 13
1 2 1
3 2 3
4 2 10
0 0 0

Sample output 1:
27

Sample input 2:
6
2 5 14
2 1 17
2 2 12
5 1 5
2 4 7
3 2 6
1 1 1
3 4 6
2 3 9
5 2 17
3 6 11
4 1 11
3 3 17
4 5 16
6 1 2
0 0 0

Sample output 2:
78
*/
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;

    vector<vector<int>> maze(n, vector<int>(n, 0));
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int a, b, c;
    cin >> a >> b >> c;

    while(a!=0 && b!=0 && c!=0){
        maze[a-1][b-1]=c;
        cin >> a >> b >> c;
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