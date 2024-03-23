// B. River-cross pawn
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15481&fragments=46926&problemId=1467
/*
Time Limit: 1s    Memory Limit: 256M
Description:
As shown in the figure, there is a river-cross pawn at point A to go to the target point B. Walking rules: can be down, or to the right. 
At the same time, there is a horse on the other side (C point in the above figure) at any point on the board. The point where the horse 
is located and the point where all the jumps are reachable is called the control point of the opponent horse. For example, the horse at 
point C above can control 9 points (P1, P2 ... P8 and C in the figure). Pawn can not pass the control point of the other horse.

The board is represented by coordinates, point A (0,0), point B (n,m) (n,m are integers not exceeding 20, and is input by the keyboard), 
and the position coordinates of the horse are also given (convention: C<>A, while C<>B). Now you are asked to calculate the number of paths 
from the point A to point B.

Input:
The coordinates of point B (n, m) and the coordinates of the opponent's horse (X, Y) {no disc error}

Output:
An integer (the number of paths).

Sample Input:
6 6 3 2

Sample Output:
17

Sample Input 2:
20 20 4 0

Sample Output 2:
56477364570
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, m, hx, hy;
    cin >> n >> m >> hx >> hy;

    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    // (hx-2, hy-1), (hx-2, hy+1), (hx+2, hy-1), (hx+2, hy+1), (hx+1, hy-2), (hx+1, hy+2), (hx-1, hy-2), (hx-1, hy+2)

    for(ll i=0; i<=n; i++){
        for(ll j=0; j<=m; j++){
            if((i!=hx-2 || j!=hy-1) && (i!=hx-2 || j!=hy+1) && (i!=hx+2 || j!=hy-1) && (i!=hx+2 || j!=hy+1) && (i!=hx+1 || j!=hy-2) && (i!=hx+1 || j!=hy+2) && (i!=hx-1 || j!=hy-2) && (i!=hx-1 || j!=hy+2) && (i!=hx || j!=hy)){
                if(i==0 && j==0){
                    dp[i][j]= 1;
                }
                else if(i==0){
                    dp[i][j]= dp[i][j-1];
                }
                else if(j==0){
                    dp[i][j]= dp[i-1][j];
                }
                else{
                    dp[i][j]= dp[i-1][j] + dp[i][j-1];
                }
            }
        }
    }

    cout << dp[n][m] << endl;
}