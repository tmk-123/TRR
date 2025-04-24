#include<bits/stdc++.h>

using namespace std;

int n;
vector<bool> visited;
vector<vector<int>> adj;

void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adj[u][v]) dfs(v);
    }
}

int countComponents() {
    int cnt = 0;
    visited.assign(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}

int main() {
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");

    fin >> n;
    adj.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> adj[i][j];
        }
    }    

    int components = countComponents();

    vector<int> res;
    for (int i = 1; i <= n; i++) {
        visited.assign(n + 1, false);
        visited[i] = true;
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                cnt++;
                dfs(j);
            }
        }

        if (cnt > components) res.push_back(i);
    }

    fout << res.size() << endl;
    for (int x : res) fout << x << " ";
    
    fin.close();
    fout.close();
    return 0;
}