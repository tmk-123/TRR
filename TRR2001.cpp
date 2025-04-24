#include<bits/stdc++.h>

using namespace std;

int t, n, start, target;
bool found = false;
vector<vector<int>> adj;
vector<int> parent;

void dfs(int u, vector<bool>& visited) { 
   // if (found) return;
    visited[u] = true;
    if (u == target) {
        found = true;
        return;
    }

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adj[u][v] == 1) {
            parent[v] = u;
            dfs(v, visited);
        }
    }
} 

int main() {
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");

    fin >> t >> n >> start >> target;
    adj.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }

    if (t == 1) {
        int cnt = 0;
        for (int k = 1; k <= n; k++) {
            cnt += adj[start][k] * adj[k][target];
        }
        fout << cnt << endl;
    }
    else {
        vector<bool> visited(n + 1, false);
        parent.assign(n + 1, 0);
        dfs(start, visited);
        if (found) {
            vector<int> path;
            for (int v = target; v != 0; v = parent[v]) {
                path.push_back(v);
            }
            for (int i = path.size() - 1; i >= 0; i--) fout << path[i] << " ";
        }
        else fout << 0;
    }
}