#include<bits/stdc++.h>

using namespace std;

int n;
vector<bool> visited;

void dfs(int u, vector<vector<int>> adj) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adj[u][v]) dfs(v, adj);
    }
}

bool isStronglyConnected(vector<vector<int>> adj) {
    for (int i = 1; i <= n; i++) {
        visited.assign(n + 1, false);
        dfs(i, adj);
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) return false;
        }
    }
    return true;
}

bool isWeaklyConnected(vector<vector<int>> adj) {
    vector<vector<int>> v = adj;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[i][j] || v[j][i]) v[i][j] = v[j][i] = 1;
        }
    }

    visited.assign(n + 1, false);
    dfs(1, v);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}
int main() {
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");

    fin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }    
    
    if (isStronglyConnected(adj)) fout << 1;
    else if (isWeaklyConnected(adj)) fout << 2;
    else fout << 0;

    fin.close();
    fout.close();
    return 0;
}