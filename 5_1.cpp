#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, start;
vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u, vector<pair<int, int>>& dfsTree) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !visited[v]) {
            if (u > v) dfsTree.push_back({v, u});
            else dfsTree.push_back({u, v});
            dfs(v, dfsTree);
        }
    }
}

void bfs(vector<pair<int, int>>& bfsTree) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
                if (u > v) bfsTree.push_back({v, u});
                else bfsTree.push_back({u, v});
            }
        }
    }
}

int main() {
    cin >> n >> start;
    adj.assign(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    visited.assign(n + 1, false);
    vector<pair<int, int>> dfsTree;
    dfs(start, dfsTree);
    cout << "DFS tree" << endl;
    for (pair<int, int>& edge : dfsTree) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    visited.assign(n + 1, false);
    vector<pair<int, int>> bfsTree;
    bfs(bfsTree);
    cout << "BFS tree" << endl;
    for (pair<int, int>& edge : bfsTree) {
        cout << edge.first << " " << edge.second << endl;
    }
}