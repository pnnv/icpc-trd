// Theme: Lowest Common Ancestor

// Algorithm: Binary Lifting
// Complextiry: O(N * log(N) * log(N))

vector<vector<int>> graph;
vector<vector<int>> up;
vector<int> tin, tout;

int timer;

// l == log(N) (~20)
int l;

void dfs(int cur, int p = -1) {
    tin[cur] = timer++;

    up[cur][0] = p;
    for (int i = 1; i <= l; i++)
        up[cur][i] = up[up[cur][i - 1]][i - 1];

    for (auto &to : graph[cur]) {
        if (to == p) continue;
        dfs(to, cur);
    }

    tout[cur] = timer++;
}

void preprocess(int u) {
    l = (int) ceil(log2(sz));
    up.assign(sz, vector<int>(l + 1));
    timer = 0;
    dfs(u, u);
}

bool is_anc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (is_anc(u, v))
        return v;
    if (is_anc(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_anc(up[v][i], u))
            v = up[v][i];
    }
    return up[v][0];
}