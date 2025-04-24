#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> ans;

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
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                res.push_back(u);

                for (int v = 1; v <= n; v++) {
                    if (!visited[v] && adj[u][v] == 1) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
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

    fin.close();
    fout.close();
    return 0;
}