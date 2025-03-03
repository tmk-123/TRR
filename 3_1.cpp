#include<iostream>
#include<vector>
using namespace std;

int n;

void dfs(int u, vector<vector<int>> adj, vector<bool>& visited) {
    cout << u << " ";
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v, adj, visited);
        }
    }
}
int main() {
    cin >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));
    vector<bool> visited(n + 1, false);
 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }
    
    dfs(1, v, visited);
}