// Packing Limited and Unlimited Items
// https://xjoi.net/contest/5167/problem/2
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12849&fragments=31106&problemId=3668
/*
Time Limit: 1s    Memory  Limit: 128M
Description :
A traveler has a backpack of a maximum capacity V kilograms (kg). There are now n items with weights of W1, W2, ..., Wn. And 
these items each have the values of C1, C2, ..., Cn. Some items can only be taken once (01 items), some items can be taken 
unlimited times (complete items), and some items can be taken up to an upper limit (multiple items) by maximum.

Pelase find a way to package these items to the backpack so that
1, the total weight does not exceed the capacity (V) of the backpage, and meanwhile
2, these items in the backpack in total have the maximum values if you add each individual value to gether.

Input :
The first line: two integers, V (package capacity, V <= 200), N (number of items, N <= 30);
Line 2 to N+1: Each line has three integers Wi, Ci, Pi. The first two integers respectively represents the weight and value of 
each item. Any non-zero Pi means the how many time item-i can be purchased by maximum. Pi=0 means, however, means that item can 
be purchased (and packed into the backpack) unlimited times. 0<=Pi<=20.

Output:
One number as the maximum total value of the items that can be packed to the backpack.

Sample input:
10 3
2 1 0
3 3 1
4 5 4

Sample output:
11

Hint:
Choose 1 piece for the first item and 2 pieces for the third item.
*/
// Etaw
// #include <bits/stdc++.h>
// using namespace std;
 
// int main() {
//   int v, n; cin>>v>>n;
//   vector<int> weight;
//   vector<int> value;
//   for (int i=0; i<n; i++) {
//     int a, b, c; cin>>a>>b>>c;
//     if (c==0) {
//       c=v/a;
//     }
//     for (int j=0; j<c; j++) {
//       weight.push_back(a);
//       value.push_back(b);
//     }
//   }
//   vector<int> dp(v+1, 0);
//   for (int i=0; i<weight.size(); i++) {
//     for (int j=v; j>=weight[i]; j--) {
//       dp[j]=max(dp[j], dp[j-weight[i]]+value[i]);
//     }
//   }
//   cout<<dp[v];
// }

// Ev
#include<bits/stdc++.h>
using namespace std;

int main(){
    int v, n; //capacity, items
    cin >> v >> n;

    vector<int> weights(n, 0);
    vector<int> values(n, 0);
    vector<int> limits(n, 0);
    vector<int> dp(v+1, 0);

    for(int i=0; i<n; i++){
        cin >> weights[i] >> values[i] >> limits[i];
        if(limits[i]==0){
            limits[i] = v/weights[i];
        }
    }

    for(int max_index=0; max_index<n; max_index++){
        for(int quantity=0; quantity<limits[max_index]; quantity++){
            for(int capacity=v; capacity>=weights[max_index]; capacity--){
                dp[capacity] = max(dp[capacity], dp[capacity-weights[max_index]] + values[max_index]);
            }
        }
    }

    cout << dp[v];
}