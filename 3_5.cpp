#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int n;
int s, t;

bool dfs(int u, vector<vector<int>> a, vector<bool> &visited, vector<int>& path) {
    visited[u] = true;
    path.push_back(u);
    
    if (u == t) return true;
    
    for (int v = 1; v <= n; v++) {
        if (a[u][v] == 1 && !visited[v]) {
            if (dfs(v, a, visited, path)) return true;
        }    
    }
    
    path.pop_back();
    return false;
}

bool bfs(vector<vector<int>> a, vector<bool>& visited, vector<int>& path) {
    queue<vector<int>> q;
    q.push({s});
    visited[s] = true;
    
    while (!q.empty()) {
        vector<int> currPath = q.front();
        q.pop();    
        int u = currPath.back();
        
        if (u == t) {
            path = currPath;
            return true;
        }
        
        for (int v = 1; v <= n; v++) {
            if (a[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                vector<int> newPath = currPath;
                newPath.push_back(v);
                q.push(newPath);
            } 
        }
    }
    return false;
}

int main() {
    cin >> n >> s >> t;
    
    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<int> dfsPath, bfsPath;
    vector<bool> visitedDfs(n + 1, false);
    vector<bool> visitedBfs(n + 1, false);
    
    bool foundDfs = dfs(s, a, visitedDfs, dfsPath);
    bool foundBfs = bfs(a, visitedBfs, bfsPath);
    
    if (!foundDfs || !foundBfs) cout << "no path\n";
    else {
        cout << "DFS path: ";
        for (int i = dfsPath.size() - 1; i >= 0; i --) {
            cout << dfsPath[i] << " ";
        }
        cout << endl;
        
        cout << "BFS path: ";
        for (int i = bfsPath.size() - 1; i >= 0; i--) {
            cout << bfsPath[i] << " ";
        }
        cout << endl;
    }
}   