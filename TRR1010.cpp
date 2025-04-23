#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n;
    fin >> t >> n;
    vector<int> degree(n + 1, 0);
    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            fin >> x;
            if (0 < x && x <= 50) {
                degree[i]++;
                if (i < j) edges.push_back({i, j, x});
            }
        }
    }

    if (t == 1) {
        for (int i = 1; i <= n; i++) {
            fout << degree[i] << " ";
        }
    }
    else {
        fout << n << " " << edges.size() << endl;
        for (auto& e : edges) {
            fout << e.u << " " << e.v << " " << e.w << endl;
        }
    }

    fin.close();
    fout.close();
}