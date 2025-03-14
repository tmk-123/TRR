#include<iostream>
#include<vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] == 1 && !visited[v]) {
            dfs(v);
        }
    }
}

int countComponents() {
    visited.assign(n + 1, false);
    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components++;
            dfs(i);
        }
    }
    return components;
}

int main() {
    cin >> n;
    adj.assign(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    int baseComponents = countComponents();
    
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (adj[u][v]) {
                adj[u][v] = adj[v][u] = 0;
                int newComponents = countComponents();
                if (newComponents > baseComponents) cout << u << " " << v << endl;
                adj[u][v] = adj[v][u] = 1;
            }
        }
    }
}