#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n;
    fin >> t >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<int> degree(n + 1, 0);
    vector<pair<int, int>> adj;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> v[i][j];
            if (v[i][j]) {
                if (i < j) adj.emplace_back(i, j);
                degree[i]++;
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << degree[i] << " ";
        }
    }
    else {
        fout << n << " " << adj.size() << endl;
        for (auto& [u, v] : adj) {
            fout << u << " " << v << endl;
        }
    }

    fin.close();
    fout.close();
}