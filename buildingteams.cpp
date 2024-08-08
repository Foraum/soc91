#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<int> color;

bool dfs(int u, int c) {
    color[u] = c;

    for (int v : g[u]) {
        if (color[v] == 0) { 
            if (!dfs(v, 3 - c)) 
                return false;
        } 
        else if (color[v] == c) {
            return false;
        }
    }
    return true;
}

bool color_all() {
    for (int i = 1; i <= n; ++i) {
        if (color[i] == 0) { 
            if (!dfs(i, 1)) 
                return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    g.resize(n + 1);
    color.resize(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (!color_all()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 1; i <= n; ++i) {
            cout << color[i] << " ";
        }
    }

    return 0;
}
