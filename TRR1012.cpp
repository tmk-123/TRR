#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n;
    fin >> t >> n;
    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<pair<int, int>> v;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
            if (adj[i][j] == 1) {
                inDegree[j]++;
                outDegree[i]++;
                v.push_back({i, j});
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << inDegree[i] << " " << outDegree[i] << endl;
        }
    }
    else {
        fout << n << " " << v.size() << endl;
        for (auto& [u, v] : v) {
            fout << u << " " << v << endl;
        }
    }
}