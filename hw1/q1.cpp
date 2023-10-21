// Minimizing Coins
// https://xjoi.net/contest/5005/problem/1
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12836&fragments=31102&problemId=14089
/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x 
using the available coins in such a way that the number of coins is minimal.

For example, if the coins are {1,5,7} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c1,c2,…,cn: the value of each coin.

Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print −1.

Constraints
1≤n≤100
1≤x≤10^6
1≤ci≤10^6

Sample Input:
3 11
1 5 7

Sample Output:
3

Sample Input 2:
100 1000000
649304 85832 159093 841262 930486 225095 306941 914339 469211 156923 460959 236712 440066 842678 379057 615269 321673 694036 378785 792217 
78290 15844 644234 752342 102458 30237 191522 388758 697655 113684 20857 639493 641307 527161 977787 505822 196847 735190 169901 417528 342499 
102964 907594 780802 577476 162325 790726 579970 148134 144070 624899 392951 594195 813112 534969 856431 25058 630213 641105 636550 762730 
873997 275210 717753 243026 915205 52253 613173 751823 647785 928932 305278 858885 496267 717378 426281 245531 139541 942976 912031 550043 
194533 504278 552822 805186 950257 673230 484067 790808 762595 590958 799224 711398 599947 858840 212470 820350 710862 546121 159727

Sameple Output 2:
4

Hint:
For Minimizing Coins, to pass all tests you might need to implement the iterative solution.
- That is, starting from the smallest subproblems (when x = 0, dp[0] = 0), use the state transition 
  dp[x] = min(1+dp[x-coin_values[0]], 1+dp[x-coin_values[1], ...) to sequentially compute the solution with increasing x, 
  until you finally reach the solution to the target x given in the problem statement.
- Recursive solution with memoization might still fail one test for timeout.
And, do not forget implementing the last sentence of the problem statement: 
"If it is not possible to produce the desired sum, print −1."
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   int n, x; cin>>n>>x;
//   vector<int> ans(x+1, -1);
//   vector<int> coins(n);
//   for (int i=0; i<n; i++) {
//     cin>>coins[i];
//     if (coins[i]>x) {
//       continue;
//     }
//     ans[coins[i]]=1;
//   }
//   sort(coins.begin(), coins.end());
//   ans[0]=0;
//   for (int i=1; i<=x; i++) {
//     int mini=-1;
//     if (ans[i]==-1) {
//       ans[i]=0;
//       for (int j=0; j<n; j++) {
//         if ((i-coins[j])<0) {
//           break;
//         }
//         if (ans[i-coins[j]]==-1) {
//           continue;
//         }
//         else {
//           ans[i]=ans[i-coins[j]]+1;
//           if (mini==-1) {
//             mini=ans[i];
//           }
//           else {
//             if (ans[i]<mini) {
//               mini=ans[i];
//             }
//             else {
//               ans[i]=mini;
//             }
//           }
//         }
//       }
//       if (ans[i]==0) {
//         ans[i]=-1;
//       }
//     }
//   }
//   cout<<ans[x];
// }

// Ev
#include<bits/stdc++.h>
using namespace std;
int n, x;
vector<int> dp(1000001, -1);
vector<int> c(100);

int calc(int a){
    if(dp[a]!=-1){
        return dp[a];
    }
    for(int i=1; i<a+1; i++){
        if(dp[i]!=-1){
            continue;
        }
        else{
            int mini=-1;
            for(int j=0; j<n; j++){
                if(i-c[j]<0){
                    continue;
                }
                if(dp[i - c[j]] == -1) { // dp value builds from bottom up, if its -1, you don't have to try again!!
                  continue;
                }
                if(mini!=-1){
                    mini=min(mini, calc(i-c[j]));
                }
                else{
                    mini = calc(i-c[j]);
                }
            }
            if(mini==-1){
                dp[i]=-1;
            }
            else{
                dp[i] = 1 + mini;
            }
        }
    }
    return dp[a];
}

int main(){
    cin >> n >> x;
    
    for(int i=0; i<n; i++){
        cin >> c[i];
        if (c[i] > x) continue;
        dp[c[i]]=1;
    }

    dp[0]=0;

    cout << calc(x);
}