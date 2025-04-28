#include<bits/stdc++.h>

using namespace std;

int n, start;
vector<vector<int>> c;
vector<bool> visited;
vector<int> path, bestPath;
int minCost = INT_MAX;

void Try(int u, int cnt, int cost) {
    if (cost >= minCost) return;

    if (cnt == n) {
        // nếu có cạnh về start
        if (0 < c[u][start] && c[u][start] <= 50) {
            int totalCost = cost + c[u][start];
            if (totalCost < minCost) {
                minCost = totalCost;
                bestPath = path;
            }
        }
        return;
    }

    for (int v = 1; v <= n; v++) {
        if (!visited[v] && 0 < c[u][v] && c[u][v] <= 50) {
            visited[v] = true;
            path.push_back(v);
            Try(v, cnt + 1, cost + c[u][v]);
            path.pop_back();
            visited[v] = false;
        }
    }
}
int main() {
    cin >> n >> start;
    
    c.assign(n + 1, vector<int>(n + 1));
    visited.assign(n + 1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    visited[start] = true;
    path.push_back(start);
    Try(start, 1, 0);

    if (minCost == INT_MAX) {
        cout << 0 << endl;
    } 
    else {
        cout << minCost << endl;
        for (int u : bestPath) cout << u << " ";
        cout << start << endl;
    }
}        