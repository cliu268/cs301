// Truck delivery
// https://xjoi.net/contest/5119/problem/4
/*
There are n items. The i-th one's volume is v_i. A truck's maximum capacity is m. Please find out the minimum waste space if 
the truck deliver the items.

The first line of input has two integers: n and m.
The second line of input has n integers, representing the volumes of the n items.

Sample input:
3 5
2 3 3

Sample output:
0

Constraints:
n<=100000
m<=100000
v_i<=100000

Hint:
Try to implement all the problems using the most efficient method: iterative with 1-D dp array.
For truck delivery, use scanf() and print() for inputs and outputs to save time.
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   int n, m; cin>>n>>m;
//   vector<int> volumes(n);
//   for (int i=0; i<n; i++) {
//     cin>>volumes[i];
//   }
//   vector<int> dp(m+1, 0);
//   for (int i=0; i<n; i++) {
//     for (int j=m; j>=volumes[i]; j--) {
//       dp[j]=max(dp[j], dp[j-volumes[i]]+volumes[i]);
//     }
//   }
//   cout<<m-dp[m];
// }

// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> w(n, 0);
    vector<int> dp(m+1, 0);

    for(int i=0; i<n; i++){
        scanf("%d", &w[i]);
    }

    for(int max_index=0; max_index<n; max_index++){
        for(int capacity=m; capacity>=w[max_index]; capacity--){
            dp[capacity] = max(dp[capacity], dp[capacity-w[max_index]]+w[max_index]);
        }
    }

    cout << m - dp[m];
}