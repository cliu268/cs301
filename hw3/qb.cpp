// B. Multiplication Puzzle
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15050&fragments=45038&problemId=15787
/*
Time Limit: 1s    Memory Limit: 256M

Description:
The multiplication puzzle is played with a row of cards, each containing a single positive integer. 
During the move player takes one card out of the row and scores the number of points equal to the product of the number on the card 
taken and the numbers on the cards on the left and on the right of it. It is not allowed to take out the first and the last card in the row. 
After the final move, only two cards are left in the row.

The goal is to take cards in such order as to minimize the total number of scored points.

For example, if cards in the row contain numbers 10 1 50 20 5, player might take a card with 1, then 20 and 50, scoring
10*1*50 + 50*20*5 + 10*50*5 = 500+5000+2500 = 8000

If he would take the cards in the opposite order, i.e. 50, then 20, then 1, the score would be
1*50*20 + 1*20*5 + 10*1*5 = 1000+100+50 = 1150.
 
Input Format:
The first line of the input contains the number of cards N (3 <= N <= 100). 
The second line contains N integers in the range from 1 to 100, separated by spaces.

Output Format:
Output must contain a single integer - the minimal score.

Sample Input:
6
10 1 50 50 20 5

Sample Output:
3650
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> num(101, 0);
    vector<vector<int>> dp(101, vector<int>(101, 0));

    for(int i=1; i<n+1; i++){
        cin >> num[i];
    }

    for(int len=3; len<=n; len++){
        for(int i=1, j=len; j<=n; i++, j++){
            dp[i][j]=INT_MAX;
            for(int k=i+1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + num[i]*num[k]*num[j]);
            }
        }
    }

    cout << dp[1][n];

}