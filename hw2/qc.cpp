// C. Chorus formation
// https://www.xinyoudui.com/contest?courses=649&books=476&pages=12839&fragments=31103&problemId=3663
/*
Time Limit: 1s    Memory  Limit: 128M 

Description:
N students stand in a row, and the music teacher asked the (N - K) students to leave, so that the remaining 
K students are arranged in a chorus formation.

The chorus formation refers to such a formation: 
K students are numbered 
1,2,...,K from left to right, and their heights are T1, T2,..., TK, and their height meets 
T1 < T2 < ... < Ti, Ti > Ti+1 >...>TK(1 ≤ i ≤ K).

Given the height of all N students, please calculate the minimum students to leave to make the remaining students line up in a chorus formation.

Input :
The first line has an integer N (2 ≤ N ≤ 100), indicating the total number of students.
The second line has N integers separated by spaces. The i-th integer Ti(130 ≤ Ti ≤ 230) is the height (cm) of the i-th student.

Output :
An integer, which means the minimum number of students needed to leave.

Sample Input:
8
186 186 150 200 160 130 197 220

Sample output:
4

Appointment:
For 50% of the data,  n ≤ 20;
For 100% of the data, n ≤ 100.
*/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> s(101, 0);
vector<int> a(101, 0);

int dpi(int b){
    for(int i=1; i<b; i++){
        for(int j=0; j<i; j++){
            if(s[j]<s[i]){
                a[i]=max(a[i], a[j]+1);
            }
        }
        if(a[i]==0){
            a[i]=1;
        }
    }

    int ans=0;
    for(int i=0; i<b; i++){
        ans=max(ans, a[i]);
    }
    return ans;
}

int dpd(int m, int b){
    for(int i=m+1; i<b; i++){
        for(int j=m; j<i; j++){
            if(s[j]>s[i]){
                a[i]=max(a[i], a[j]+1);
            }
        }
        if(a[i]==0){
            a[i]=1;
        }
    }

    int ans=0;
    for(int i=m; i<b; i++){
        ans=max(ans, a[i]);
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    a[0]=1;
    int sum=0;
    
    int mid= n/2;
    sum += dpi(mid);
    // cout << sum << endl;

    fill(a.begin(), a.end(), 0);
    a[mid]=1;
    sum += dpd(mid, n);
    // cout << sum << endl;

    cout << n - sum;
}