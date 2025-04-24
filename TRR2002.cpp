#include<bits/stdc++.h>

using namespace std;

int t, n, start, target;

vector<vector<int>> adj;

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
        vector<int> parent(n + 1, 0);
        bool found = false;

        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == target) {
                found = true;
                break;
            }

            for (int v = 1; v <= n; v++) {
                if (!visited[v] && adj[u][v] == 1) {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
            }
        }

        if (found) {
            vector<int> path;
            for (int v = target; v != start; v = parent[v]) {
                path.push_back(v);
            }
            path.push_back(start);
            for (int i = path.size() - 1; i >= 0; i--) {
                fout << path[i] << " ";
            }
        }
        else fout << 0;
    }
}