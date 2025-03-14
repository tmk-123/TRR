#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int n, start;
vector<vector<int>> adj;
vector<int> res;

void findEulerPath() {
    stack<int> st;
    st.push(start);
    
    while (!st.empty()) {
        int u = st.top();
        bool found = false;
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v]) {
                adj[u][v] = adj[v][u] = 0;
                st.push(v);
                found = true;
                break;
            }
        }
        
        if (!found) {
            res.push_back(u);
            st.pop();
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
    
    findEulerPath();
    
    for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
}