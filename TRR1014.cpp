#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n;
    fin >> t >> n;
    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<pair<int, int>> edges;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
            if (adj[i][j] == 1) {
                inDegree[j]++;
                outDegree[i]++;
                edges.push_back({i, j});
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << inDegree[i] << " " << outDegree[i] << endl;
        }
    }
    else {
        int m = edges.size();
        fout << n << " " << m << endl;
        vector<vector<int>> lt(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < m; i++) {
            int u = edges[i].first, v = edges[i].second;
            lt[u][i + 1] = 1;
            lt[v][i + 1] = -1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                fout << lt[i][j] << " ";
            }
            fout << endl;
        }
    }
}