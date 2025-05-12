#include<iostream>
#include<vector>

using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> dist;
vector<vector<int>> nextNode;

void print(int u, int v) {
    if (u == v) {
        cout << " " << u;
        return;
    }
    cout << u << " -> ";
    while (u != v) {
        u = nextNode[u][v];
        if (u == v) cout << u;
        else cout << u << " --> ";
    }
}

int main() {
    cin >> n;
    dist.assign(n + 1, vector<int>(n + 1, INF));
    nextNode.assign(n + 1, vector<int>(n + 1, -1));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            
            if (i == j) dist[i][j] = 0;
            else if (w != 0) dist[i][j] = w;
            nextNode[i][j] = j;
        }
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nextNode[i][j] = nextNode[i][k];
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "K/c " << i << " -> " << j << " = " << dist[i][j] << ";   ";
            print(i, j);
            cout << endl;
        }
    }
}