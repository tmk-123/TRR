#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n , m;
    fin >> t >> n >> m;

    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
        outDegree[u]++;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << inDegree[i] << " " << outDegree[i] << endl;
        }
    }
    else {
        fout << n << endl;
        for (int i = 1; i <= n; i++) {
            fout << adj[i].size() << " ";
            for (int j : adj[i]) {
                fout << j << " "; 
            }
            fout << endl;
        }
    }
}