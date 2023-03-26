#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m; cin>>n>>m;
    vector<vector<int>> adj(10000);
    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int s, t; cin>>s>>t;
    vector<int> dist(10000, 10000);
    dist[s]=0;
    for (int j=0; j<n; j++) {
        if (dist[j]==10000) {
            continue;
        }
        for (int i : adj[j]) {
            dist[i]=min(dist[i], dist[j]+1);
        }
    }
    cout<<dist[t];
}