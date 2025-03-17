#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX = 100;
int parent[MAX], Rank[MAX], n;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    if (a.w == b.w) {
        if (a.u == b.u) return a.v < b.v;
        return a.u < b.u;
    }
    return a.w < b.w;
}

int find(int u) {
    if (parent[u] != u) parent[u] = find(parent[u]);
    return parent[u];
}

bool unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    
    if (rootU == rootV) return false;
    
    if (Rank[rootU] > Rank[rootV]) parent[rootV] = rootU;
    else if (Rank[rootV] > Rank[rootU]) parent[rootU] = rootV;
    else {
        parent[rootV] = rootU;
        Rank[rootU]++;
    }
    return true;
}

void kruskalMST(vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        Rank[i] = 0;
    }
    
    vector<Edge> mst;
    int totalWeight = 0;
    
    for (int i = 0; i < edges.size(); i++) {
        if (unionSet(edges[i].u, edges[i].v)) {
            mst.push_back(edges[i]);
            totalWeight += edges[i].w;
            if (mst.size() == n - 1) break;
        }
    }
    
    cout << "dH = " << totalWeight << endl;
    for (int i = 0; i < mst.size(); i++) {
        cout << mst[i].u << " " << mst[i].v << endl;
    }
}

int main() {
    cin >> n;
    vector<Edge> edges;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int w;
            cin >> w;
            if (i < j && w > 0) {
                edges.push_back({i, j, w});
            }
        }
    }
    
    kruskalMST(edges);
}