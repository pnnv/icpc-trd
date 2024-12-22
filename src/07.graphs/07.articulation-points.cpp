// Theme: Articulation Points And VCC

vector<pair<int, int>> edges;
vector<vector<int>> graph;
vector<int> used;

vector<int> height;
vector<int> up;

// Algorithm: Articulation Points
// Complexity: O(N + M)

set<int> art_points;

void dfs_artics(int cur, int p = -1) {
    used[cur] = 1;
    up[cur] = height[cur];

    int desc_count = 0;

    for (auto &ind : g[cur]) {
        int to = cur ^ edges[ind].ff ^ edges[ind].ss;
        if (to == p) continue;
        if (used[to]) {
            up[cur] = min(up[cur], height[to]);
        }
        else {
            desc_count++;
            height[to] = height[cur] + 1;
            dfs_artics(to, cur);
            up[cur] = min(up[cur], up[to]);
            if (up[to] >= height[cur] && p != -1)
                art_points.insert(cur);
        }
    }

    if (p == -1 && desc_count > 1) {
        art_points.insert(cur);
    }
}

// Algorithm: VCC
// Complexity: O(N + M)

vector<vector<int>> vcc;

void dfs_artics_comps(int cur, int p = -1) {
    used[cur] = 1;
    up[cur] = height[cur];

    for (auto &ind : g[cur]) {
        int to = cur ^ edges[ind].ff ^ edges[ind].ss;
        if (to == p) continue;
        if (used[to]) {
            up[cur] = min(up[cur], height[to]);
            if (height[to] < height[cur]) st.push_back(ind);
        }
        else {
            int sz = st.size();
            st.push_back(ind);
            height[to] = height[cur] + 1;
            dfs_artics_comps(to, cur);
            up[cur] = min(up[cur], up[to]);
            if (up[to] >= height[cur])
                vcc.push_back(add_comp(st, sz));
        }
    }
}