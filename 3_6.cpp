#include<iostream>
#include<vector>

using namespace std;

int n;

bool dfs(vector<bool>& visited, vector<vector<int>> adj, int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(visited, adj, v);
        }
    }
}

bool isStronglyConnected(vector<vector<int>> adj) {
    vector<bool> visited(n + 1, false);
    dfs(visited, adj, 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    
    vector<vector<int>> trans(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            trans[j][i] = adj[i][j];
        }
    }
    
    fill(visited.begin(), visited.end(), false);
    dfs(visited, adj, 1);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}
int main() {
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    if (isStronglyConnected(adj)) cout << "strongly connected";
    else cout << "not strongly connnected";
}