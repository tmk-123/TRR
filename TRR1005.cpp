#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n, m;
    fin >> t >> n >> m;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; 
        fin >> u >> v;
        degree[u]++;
        degree[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << degree[i] << " ";
        }
    }
    else {
        fout << n << endl;
        for (int i = 1; i <= n; i++) {
            fout << adj[i].size() << " ";
            for (int j : adj[i]) fout << j << " ";
            fout << endl;
        } 
    }

    fin.close();
    fout.close();
}