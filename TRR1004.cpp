#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n, m;
    fin >> t >> n >> m;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v; 
        fin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
        degree[u]++;
        degree[v]++;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << degree[i] << " ";
        }
    }
    else {
        fout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fout << adj[i][j] << " ";
            }
            fout << endl;
        } 
    }

    fin.close();
    fout.close();
}