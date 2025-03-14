#include<iostream>
#include<vector>

using namespace std;

int n, start;
vector<vector<int>> adj;
vector<int> path;
vector<bool> visited;

// pos: vi tri hien tai, pos - 1: vi tri truoc
void Try(int pos, int start) {
    if (pos == n) {
        if (adj[ path[pos - 1] ][start] == 1) {
            for (int i = 0; i < n; i++) cout << path[i] << " ";
            cout << start << endl;
        }
        return;
    }    
    
    for (int v = 1; v <= n; v++) {
        if (!visited[v] && adj[ path[pos - 1] ][v] == 1) {
            visited[v] = true;
            path[pos] = v;
            Try(pos + 1, start);
            visited[v] = false;
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
    
    path.resize(n);
    visited.assign(n + 1, false);
    
    path[0] = start;
    visited[start] = true;
    
    Try(1, start);
}