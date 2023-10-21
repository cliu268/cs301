// C. Stick Divisions
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=15050&fragments=45038&problemId=14058
/*
Time limit: 1.00 s
Memory limit: 512 MB

You have a stick of length x. You want to break it into n sticks of given lengths. The total length of the n sticks is x.

On each move you can take a stick and break it into two sticks. The cost of such an operation is the length of the original stick.

What is the minimum total cost to break the sticks?

Input
The first input line has two integers x and n: the length of the given stick, and the number of sticks to break into. 
The order of the n sticks does not matter.

The second line has n integers d1, d2, ... , dn : the length of each stick.

Output
Print one integer: the minimum total cost.

Constraints
1 ≤ x ≤ 10^9  
1 ≤ n ≤ 2⋅10^5 
∑di = x

Example Input:
8 3
2 3 3

Example Output:
13

Explanation: You first divide the stick of length 8 into sticks of length 3 and 5 (cost 8). 
After this, you divide the stick of length 5 into sticks of length 2 and 3 (cost 5). 
The total cost is 8+5=13.
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    vector<int> s(n, 0);
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0; i<n; i++){
        cin >> s[i];
        pq.push(s[i]);
    }

    long long ans=0;

    while(pq.size()>=2){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int sum=a+b;
        ans+=sum;
        pq.push(sum);
    }

    cout << ans;
}