// Theme: Connectivity Components

vector<vector<int>> graph;
vector<int> used;

// Algorithm: Connected Components
// Complexity: O(N + M)

vector<vector<int>> cc;

void dfs_cc(int cur, int p = -1) {
    used[cur] = 1;
    cc.back().push_back(cur);

    for (auto &to : graph[cur]) {
        if (to == p || used[to]) continue;
        dfs_cc(to, cur);
    }
}

for (int u = 0; u < n; i++)
    if (!used[u])
        dfs_cc(u);

// Algorithm: Strongly Connected Components
// Complexity: O(N + M)

vector<vector<int>> rgraph;

vector<vector<int>> topsort;

vector<vector<int>> scc;

void dfs_scc(int cur, int p = -1) {
    used[cur] = 1;
    scc.back().push_back(cur);

    for (auto &to : rgraph[cur]) {
        if (to == p || used[to]) continue;
        dfs_scc(to, cur);
    }
}

for (auto &u: topsort)
    if (!used[u])
        dfs_scc(u);

