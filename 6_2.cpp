#include<iostream>
#include<queue>
#include<climits>
#include<vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, s});
    dist[s] = 0;
    
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (visited[u]) continue;
        visited[u] = true; // cố định đỉnh
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] && dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << "K/c " << s << " -> " << i << " = ";
        if (dist[i] == INT_MAX) {
            cout << "INF;\n";
            continue;
        }
        
        cout << dist[i] << ";";
        int space = 10 - to_string(dist[i]).length() - to_string(i).length();
        cout << string(space, ' ');
        
        vector<int> path;
        for (int v = i; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        
        for (int j = 0; j < path.size(); j++) {
            cout << path[j];
            if (j < path.size() - 1) cout << " <- ";
        }
        if (s == i) cout << " <- " << i;
        cout << endl;
    }
}