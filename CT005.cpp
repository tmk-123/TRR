#include <bits/stdc++.h>

using namespace std;

int n, m, u;
vector<vector<int>> adjList;
vector<bool> visited;
vector<int> path;
vector<vector<int>> res;

void Try(int pos, int count) {
    if (count == n) {
        for (int next : adjList[pos]) {
            if (next == u) {
                path.push_back(u);
                res.push_back(path);
                path.pop_back();
                break;
            }
        }
        return;
    }

    for (int next : adjList[pos]) {
        if (!visited[next]) {
            visited[next] = true;
            path.push_back(next);
            Try(next, count + 1);
            path.pop_back();
            visited[next] = false;
        }
    }
}

int main() {    
    cin >> n >> m >> u;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    adjList.assign(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    visited.assign(n + 1, false);
    path.push_back(u);
    visited[u] = true;

    Try(u, 1);

    if (res.empty()) {
        cout << 0 << endl;
    } else {
        cout << res.size() << endl;
        for (auto& cycle : res) {
            for (int v : cycle) cout << v << " ";
            cout << endl;
        }
    }

    return 0;
}
