#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    int adj[n + 1][n + 1];
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> adj[i][j];
        }
    }
    
    stack<int> st;
    st.push(1);
    visited[1] = true;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        cout << u << " ";
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[v]) {
                visited[v] = true;
                st.push(v);
                break;
            }
        }
    }
}