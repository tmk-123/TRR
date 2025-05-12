#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

int n, s;

struct Edge {
    int u, v, w;
};

int main() {
    cin >> n >> s;
    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (w != 0) edges.push_back({i, j, w}); 
        }
    }
    
    vector<int> dist(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    dist[s] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (Edge e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    } 
    
    for (int i = 1; i <= n; i++) {
        cout << "K/c " << s << " -> " << i << " = ";
        if (dist[i] == INT_MAX) cout << "INF;\n";
        else {
            cout << dist[i] << ";"; 
            int space = 10 - to_string(dist[i]).length() - to_string(i).length();
            cout << string(space, ' ');
            
            vector<int> path;
            for (int v = i; v != -1; v = parent[v]) path.push_back(v);
            
            for (int j = 0; j < path.size(); j++) {
                cout << path[j];
                if (j < path.size() - 1) cout << " <- ";
            }
            if (s == i) cout << " <- " << i;
            cout << endl;
        }
    }
}