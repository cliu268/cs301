// Tree Distances I
// https://xjoi.net/contest/5452/problem/2
/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.

Input
The first input line contains an integer n: the number of nodes. The nodes are numbered 1,2,…,n.
Then there are n−1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output
Print n integers: for each node 1,2,…,n, the maximum distance to another node.

Constraints
1≤n≤2⋅10^5
1≤a,b≤n

Example Input:
5
1 2
1 3
3 4
3 5

Output:
2 3 2 3 3
*/

// Ev
#include<bits/stdc++.h>
using namespace std;

const int N_MAX = 2 * 1e5 + 1; 
vector<vector<int>> tree(N_MAX);
vector<int> visited(N_MAX, 0);
vector<int> answers(N_MAX, 0);

void dfs(int distance, int node){
    answers[node] = max(answers[node], distance);
    // cout << answers[node] << " " << node << endl;
    for(int i=0; i<tree[node].size(); i++){
        if(visited[tree[node][i]] == 0){
            visited[tree[node][i]] = 1;
            dfs(distance + 1, tree[node][i]);
        }
    }
}

int main(){
    int n; cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b; 
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // cout << "mark " << endl;

    for(int i=1; i<=n; i++){
        // cout << i << ": " << endl;
        visited[i] = 1;
        dfs(0, i);
        std::fill(visited.begin(), visited.end(), 0);
    }
    
    for(int i=1; i<=n; i++){
        cout << answers[i] << " ";
    }
    
}