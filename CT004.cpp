#include <bits/stdc++.h>

using namespace std;

int n, u;
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

    cin >> n >> u;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    adjList.assign(n + 1, vector<int>());

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
            if (adj[i][j]) adjList[i].push_back(j);
        }
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
