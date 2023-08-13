#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void dfs(int u) {
    // Complexity of this part is O(n+e);
    visited[u] = true;
    cout << "Visiting Node " << u << endl;
    for(int v : adj[u]) {
        if(visited[v]) {
            continue;
        }
        dfs(v);
    }
}

int main () {
    init_code();
    int n, e;
    cin >> n >> e;
    // Complexity of this part is O(e);
    for (int i = 0; i <= e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // Complexity of this part is O(n+e)
    // run dfs for any node;
    dfs(1);

    // Total Complexity of DFS should be O(n+e);
    return 0;
}