#include<iostream>
#include<vector>

using namespace std;

int n;

void dfs(int u, vector<vector<int>> adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adj[u][v] == 1) {
            dfs(v, adj, visited);
        }
    }
}
int main() {
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    int cnt = 0;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            cout << cnt << " " << i << endl;
            cnt++;
        }
    }
    cout << cnt;
}