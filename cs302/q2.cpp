#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int t; cin>>t;
    while (t--) {
		int n, m; cin>>n>>m;
        vector<vector<int>> adj(10000);
        map<pair<int, int>, int> weight;
        for (int i=0; i<m; i++) {
			int a, b, c; cin>>a>>b>>c;
            adj[a].push_back(b);
            weight[{a, b}]=c;
        }
        for (int i=1; i<=n; i++) {
            adj[0].push_back(i);
            adj[i].push_back(0);
            weight[{0, i}]=0;
            weight[{i, 0}]=0;
        }
        vector<int> dist(10000, 10000);
        dist[0]=0;
        for (int k=0; k<n-1; k++) {
            for (int i=0; i<=n; i++) {
                if (dist[i]==10000) {
                    continue;
                }
                for (int j : adj[i]) {
                    dist[j]=min(dist[j], dist[i]+weight[{i, j}]);
                }
            }
        }
        bool change=false;
        for (int i=0; i<=n; i++) {
            if (dist[i]==10000) {
                    continue;
            }
            for (int j : adj[i]) {
                if (dist[j]>(dist[i]+weight[{i, j}])) {
                    change=true;
					break;
                }
            }
            if (change) {
                break;
            }
        }
        if (change) {
            cout<<"YES\n";
        }
        else {
			cout<<"NO\n";
        }
    }
}