#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> ans;

void dfs(int u, vector<int>& res, vector<bool>& visited) {
    visited[u] = true;
    res.push_back(u);
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adj[u][v] == 1) {
            dfs(v, res, visited);
        }
    }
}

int main() {
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");

    fin >> n;
    adj.assign(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }    

    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> res;
            dfs(i, res, visited);
            sort(res.begin(), res.end());
            ans.push_back(res);
        }
    }

    fout << ans.size() << endl;
    for (auto& v : ans) {
        for (int x : v) {
            fout << x << " ";
        }
        fout << endl;
    }
}