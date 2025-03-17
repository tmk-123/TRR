#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>

using namespace std;
 
int n, start, totalWeight = 0;

struct Edge {
    int u, v, w;
};

struct Compare {
     bool operator()(const Edge &a, const Edge &b) const {
        if (a.w == b.w) {
            if (a.u == b.u) return a.v > b.v;
            return a.u > b.u;
        }
        return a.w > b.w;
    }
};

void primMST(vector<vector<int>>& graph, vector<bool>& visited) {
    priority_queue<Edge, vector<Edge>, Compare> pq;
    vector<Edge> MST;
    
    visited[start] = true;
    for (int i = 1; i <= n; i++) {
        if (graph[start][i] > 0) pq.push({start, i, graph[start][i]});
    }
    
    while (!pq.empty()) {
        Edge top = pq.top();
        pq.pop();
        
        if (visited[top.v]) continue;

        visited[top.v] = true;
        totalWeight += top.w;
        MST.push_back(top);
        
        for (int i = 1; i <= n; i++) {
            if (graph[top.v][i] > 0 && !visited[i]) {
                pq.push({top.v, i, graph[top.v][i]});
            } 
        }
    }
    
    cout << "dH = " << totalWeight << endl;
    for (Edge& e : MST) {
        cout << min(e.u, e.v) << " " << max(e.u, e.v) << endl;
    } 
}

int main() {
    cin >> n >> start;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j]; 
        }
    }
    
    vector<bool> visited(n + 1, false);
    primMST(graph, visited);
}