#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n;
    fin >> t >> n;
    vector<int> degree(n + 1, 0);
    vector<pair<int, int>> edges;
    
    for (int i = 1; i <= n; i++) {
        int size;
        fin >> size;
        degree[i] = size;
        for (int j = 0; j < size; j++) {
            int u;
            fin >> u;
            if (i < u) edges.emplace_back(i, u);
        }
    } 

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << degree[i] << " ";
        }
    }
    else {
        fout << n << " " << edges.size() << endl;
        for (auto& [u, v] : edges) {
            fout << u << " " << v << endl;
        }
        fout << endl;
    }

    fin.close();
    fout.close();
}