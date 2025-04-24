#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n , m;
    fin >> t >> n >> m;

    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<vector<int>> lt(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= m; i++) {
        int u, v;
        fin >> u >> v;
        lt[u][i] = 1;
        lt[v][i] = -1;
        outDegree[u]++;
        inDegree[v]++;
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << inDegree[i] << " " << outDegree[i] << endl;
        }
    }
    else {
        fout << n << " " << m << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                fout << lt[i][j] << " ";
            }
            fout << endl;
        }
    }
}