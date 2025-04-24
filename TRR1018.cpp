#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n;
    fin >> t >> n;

    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
    for (int u = 1; u <= n; u++) {
        int size;
        fin >> size;
        for (int j = 0; j < size; j++) {
            int v;
            fin >> v;
            adj[u][v] = 1;
            outDegree[u]++;
            inDegree[v]++;
        }
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
                fout << adj[i][j] << " ";
            }
            fout << endl;
        }
    }
}