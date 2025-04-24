#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");
    int t, n;
    fin >> t >> n;

    vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
    vector<tuple<int, int, int>> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            fin >> w;
            if (0 < w && w <= 50) {
                edges.push_back({i, j, w});
                outDegree[i]++;
                inDegree[j]++;
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << inDegree[i] << " " << outDegree[i] << endl;
        }
    }
    else {
        fout << n << " " << edges.size() << endl;
        for (auto [u, v, w] : edges) {
            fout << u << " " << v << " " << w << endl;
        }
    }
}