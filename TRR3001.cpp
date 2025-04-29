#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
int a[MAX][MAX];
vector<int> visited(MAX, 0);
int n, t, u, dem = 0;

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    dem++;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 1; i <= n; i++) {
            if (a[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                dem++;
                q.push(i);
            }
        }
    }
}

bool isEuler() {
    if (dem != n) return false;
    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) {
            deg += a[i][j];
        }
        if (deg % 2 != 0) return false;
    }
    return true;
}

bool isHalfEuler() {
    if (dem != n) return false;
    int oddDeg = 0;
    for (int i = 1; i <= n; i++) {
        int deg = 0;
        for (int j = 1; j <= n; j++) {
            deg += a[i][j];
        }
        if (deg % 2 != 0) oddDeg++;
    }
    return (oddDeg == 0 || oddDeg == 2);
}

vector<int> findEulerCycle(int start) {
    stack<int> st;
    vector<int> circuit;
    st.push(start);

    while (!st.empty()) {
        int v = st.top();
        bool hasEdge = false;
        for (int i = 1; i <= n; i++) {
            if (a[v][i] == 1) {
                hasEdge = true;
                st.push(i);
                a[v][i] = a[i][v] = 0; // xóa cạnh đi
                break;
            }
        }
        if (!hasEdge) {
            circuit.push_back(v);
            st.pop();
        }
    }

    reverse(circuit.begin(), circuit.end());
    return circuit;
}

int main() {
    ifstream fin("CT.INP");
    ofstream fout("CT.OUT");

    fin >> t;
    if (t == 1) {
        fin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fin >> a[i][j];
            }
        }

        BFS(1);

        if (isEuler()) fout << 1;
        else if (isHalfEuler()) fout << 2;
        else fout << 0;
    } 
    else if (t == 2) {
        fin >> n >> u;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fin >> a[i][j];
            }
        }

        vector<int> result = findEulerCycle(u);
        for (int v : result) {
            fout << v << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
