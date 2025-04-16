#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n;
    fin >> t >> n;
    vector<vector<int>> v(n + 1, vector<int>(n + 1));
    vector<int> degree(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> v[i][j];
            if (v[i][j]) {
                adj[i].emplace_back(j);
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
        fout << n << endl;
        for (int i = 1; i <= n; i++) {
            fout << adj[i].size() << " ";
            for (int& x : adj[i]) fout << x << " ";
            fout << endl;
        }
    }

    fin.close();
    fout.close();
}