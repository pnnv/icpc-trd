// Theme: Topological Sort

vector<vector<int>> graph;
vector<int> used;

// Algorithm: Topological Sort
// Complexity: O(N + M)

vector<int> topsort;

void dfs_topsort(int cur, int p = -1) {
    used[cur] = 1;

    for (auto &to : graph[cur]) {
        if (to == p || used[to]) continue;
        dfs(to, cur);
    }

    topsort.push_back(cur);
}

for (int u = 0; u < n; u++)
    if (!used[u])
        dfs_topsort(u);

reverse(all(topsort));