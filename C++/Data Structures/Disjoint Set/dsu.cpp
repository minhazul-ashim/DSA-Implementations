#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1e5 + 5;
int parent[N];
int parentLevel[N];

void set_dsu(int n) {
    for (int i = 1; i <= n; i++) {
        parent[i] = -1;
        parentLevel[i] = 0;
    }
}

int dsu_find(int node) {
    while(parent[node] != -1) {
        node = parent[node];
    }
    return node;
}

// Union by Size;
void unionBySize(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if(leaderA != leaderB) {
        if(parentLevel[leaderA] > parentLevel[leaderB]) {
            parent[leaderB] = leaderA;
            // parentLevel[leaderA]++;
        } else if(parentLevel[leaderB] > parentLevel[leaderA]) {
            parent[leaderA] = leaderB;
            // parentLevel[leaderB]++;
        } else {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

// Union by Rank / Level;
void unionByRank(int a, int b) {

}

// Basic Union Function for joining.
void dsu_union(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(leaderA != leaderB) {
        // This means a and b are not from the same set or same group, that means they will be unified to a single group and with a single leader.
        parent[leaderB] = leaderA;
    }
}

int main () {
    init_code();
    int n, e;
    cin >> n >> e;
    set_dsu(n);
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        unionBySize(a, b);
    }

    cout << dsu_find(1);
    return 0;
}