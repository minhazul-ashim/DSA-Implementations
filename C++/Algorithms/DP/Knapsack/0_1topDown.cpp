#include<bits/stdc++.h>
using namespace std;

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

const int N = 1000;
int memoize[N][N];

int knapsack(int n, int s, int v[], int w[]) {
    if(n == 0 || s == 0) {
        return 0;
    }
    if(memoize[n][s] != -1) {
        return memoize[n][s];
    }
    if(w[n-1] <= s) {
        int op1 = knapsack(n - 1, s - w[n - 1], v, w) + v[n - 1];
        int op2 = knapsack(n - 1, s, v, w);
        return memoize[n][s] = max(op1, op2);
    } else {
        return memoize[n][s] = knapsack(n - 1, s, v, w);
    }
}

int main () {
    init_code();
    int n;
    cin >> n;
    int v[n];
    int w[n];

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            memoize[i][j] = -1;
        }
    }

    int s;
    cin >> s;

    int result = knapsack(n, s, v, w);

    cout << result;

    return 0;
}

/*
Demo Input
4
1 5 3 2
5 2 4 3
7
*/