#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n, m;
    fin >> t >> n >> m;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> lt(n + 1, vector<int>(m + 1, 0));
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v; 
        fin >> u >> v;
        degree[u]++;
        degree[v]++;
        edges.emplace_back(u, v);
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << degree[i] << " ";
        }
    }
    else {
        fout << n << " " << m << endl;
        for (int i = 0; i < m; i++) {
            int u = edges[i].first, v = edges[i].second;
            lt[u][i + 1] = 1;
            lt[v][i + 1] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                fout << lt[i][j] << " ";
            }
            fout << endl;
        }
    }

    fin.close();
    fout.close();
}