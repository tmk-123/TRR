#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n, m;
    fin >> t >> n >> m;
    
    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 10000));
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        fin >> u >> v >> w;
        outDegree[u]++;
        inDegree[v]++;
        adj[u][v] = w;
    }
    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << inDegree[i] << " " << outDegree[i] << endl;
        }
    }
    else {
        fout << n << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) fout << 0 << " ";
                else fout << adj[i][j] << " "; 
            }
            fout << endl;
        }
    }
}