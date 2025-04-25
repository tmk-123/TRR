#include<bits/stdc++.h>

using namespace std;

int n;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adj[u][v]) dfs(v);
    }
}


int countComponents() {
    int cnt = 0;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main() {
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");

    fin >> n;
    adj.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }    

    int components = countComponents();

    vector<pair<int, int>> res;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (adj[i][j]) {
                adj[i][j] = adj[j][i] = 0;
                int newComponents = countComponents();
                if (newComponents > components) res.push_back({i, j}); 
                adj[i][j] = adj[j][i] = 1;
            }
        }
    }

    fout << res.size() << endl;
    for (auto [u, v] : res) {
        fout << u << " " << v << endl;
    }

    fin.close();
    fout.close();
    return 0;
}