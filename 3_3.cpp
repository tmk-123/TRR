#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int adj[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    vector<bool> visited;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}