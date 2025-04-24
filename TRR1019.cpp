#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n;
    fin >> t >> n;

    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<pair<int, int>> edges;
    for (int u = 1; u <= n; u++) {
        int size;
        fin >> size;
        for (int j = 0; j < size; j++) {
            int v;
            fin >> v;
            edges.push_back({u, v});
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
        int m = edges.size();
        fout << n << " " << m << endl;
        for (auto [u, v] : edges) {
            fout << u << " " << v << endl;
        } 
    }
}