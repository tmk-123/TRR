#include<bits/stdc++.h>

using namespace std;

int t, n;
vector<vector<int>> adj;

int main() {
    cin >> t >> n;
    adj.assign(n + 1, vector<int>(n + 1));
    vector<int> degree(n + 1, 0);
    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
            if (i < j && adj[i][j] == 1) {
                edges.push_back({i, j});
                degree[i]++;
                degree[j]++;
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            cout << degree[i] << " ";
        }
    }
    else {
        int m = edges.size();
        cout << n << " " << m << endl;
        for (auto [u, v] : edges) {
            cout << u << " " << v << endl;
        }
    }
}