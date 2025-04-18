#include<bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("DT.INP");
    ofstream fout("DT.OUT");

    int t, n;
    fin >> t >> n;
    vector<int> degree(n + 1, 0);
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    
    for (int i = 1; i <= n; i++) {
        int size;
        fin >> size;
        degree[i] = size;
        for (int j = 0; j < size; j++) {
            int u;
            fin >> u;
            adj[i][u] = 1;
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
            for (int j = 1; j <= n; j++) {
                fout << adj[i][j] << " ";
            }
            fout << endl;
        }
    }

    fin.close();
    fout.close();
}