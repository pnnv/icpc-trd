// Theme: Bridges And ECC

vector<pair<int, int>> edges;
vector<vector<int>> graph;
vector<int> used;

vector<int> height;
vector<int> up;

// Algorithm: Bridges
// Complexity: O(N + M)

vector<int> bridges;

void dfs_bridges(int cur, int p = -1) {
    used[cur] = 1;
    up[cur] = height[cur];
    for (auto &ind : g[cur]) {
        int to = cur ^ edges[ind].ff ^ edges[ind].ss;
        if (to == p) continue;
        if (used[to]) {
            up[cur] = min(up[cur], height[to]);
        }
        else {
            height[to] = height[cur] + 1;
            dfs_bridges(to, cur);
            up[cur] = min(up[cur], up[to]);
            if (up[to] > height[cur])
                bridges.push_back(ind);
        }
    }
}

// Algorithm: ECC
// Complexity: O(N + M)

vector<int> st;

vector<int> add_comp(vector<int> &st, int sz) {
    vector<int> comp;

    while (st.size() > sz) {
        comp.push_back(st.back());
        st.pop_back();
    }

    return comp;
}

vector<vector<int>> ecc;

void dfs_bridges_comps(int cur, int p = -1) {
    used[cur] = 1;
    up[cur] = height[cur];

    for (auto &ind : g[cur]) {
        int to = cur ^ edges[ind].ff ^ edges[ind].ss;
        if (to == p) continue;
        if (used[to]) {
            up[cur] = min(up[cur], height[to]);
        }
        else {
            int sz = st.size();
            st.push_back(to);
            height[to] = height[cur] + 1;
            dfs_bridges_comps(to, cur);
            up[cur] = min(up[cur], up[to]);
            if (up[to] > height[cur])
                ecc.push_back(add_comp(st, sz));
        }
    }
}