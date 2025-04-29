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
            if ((a[v][i] || a[i][v]) && visited[i] == 0) { // coi như vô hướng
                visited[i] = 1;
                dem++;
                q.push(i);
            }
        }
    }
}

bool isEulerDirected() {
    if (dem != n) return false;

    for (int i = 1; i <= n; i++) {
        int inDeg = 0, outDeg = 0;
        for (int j = 1; j <= n; j++) {
            inDeg += a[j][i];
            outDeg += a[i][j];
        }
        if (inDeg != outDeg) return false;
    }
    return true;
}

bool isHalfEulerDirected() {
    if (dem != n) return false;

    int startCount = 0, endCount = 0;
    for (int i = 1; i <= n; i++) {
        int inDeg = 0, outDeg = 0;
        for (int j = 1; j <= n; j++) {
            inDeg += a[j][i];
            outDeg += a[i][j];
        }
        if (outDeg - inDeg == 1) startCount++;
        else if (inDeg - outDeg == 1) endCount++;
        else if (inDeg != outDeg) return false;
    }
    return (startCount == 1 && endCount == 1);
}

vector<int> findEulerCycleDirected(int start) {
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
                a[v][i] = 0; // chỉ xóa 1 chiều
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

        if (isEulerDirected()) fout << 1;
        else if (isHalfEulerDirected()) fout << 2;
        else fout << 0;
    } 
    else if (t == 2) {
        fin >> n >> u;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                fin >> a[i][j];
            }
        }

        vector<int> result = findEulerCycleDirected(u);
        for (int v : result) {
            fout << v << " ";
        }
    }

    fin.close();
    fout.close();
    return 0;
}
