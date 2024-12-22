// Theme: Maximum Flow

int s, t, sz;

vector<edge> edges;
vector<vector<int>> fgraph;

vector<int> used;

// Algorithm: Ford-Fulkerson Algorithm
// Complexity: O(MF)

int dfs_fordfulk(int u, int bound, int flow = INF) {
    if (used[u]) return 0;
    if (u == t) return flow;

    used[u] = 1;

    for (auto &ind : fgraph[u]) {
        auto &e = edges[ind],
            &_e = edges[ind ^ 1];
        int to = e.to, res = e.res();

        if (res < bound) continue;

        int pushed = dfs_fordfulk(to, bound, min(res, flow));

        if (pushed) {
            e.flow += pushed;
            _e.flow -= pushed;
            return pushed;
        }
    }

    return 0;
}

// Algorithm: Edmonds-Karp Algorithm
// Complexity: O(N(M^2))

vector<int> p;
vector<int> pe;

void augment(int pushed) {
    int cur = t;
    while (cur != s) {
        auto &e = edges[pe[cur]],
            &_e = edges[pe[cur] ^ 1];
        e.flow += pushed;
        _e.flow -= pushed;
        cur = p[cur];
    }
}

int bfs_edmskarp(int u, int bound) {
    p.assign(sz, -1);
    pe.assign(sz, -1);

    int pushed = 0;

    queue<pair<int, int>> q;
    q.push({ u, INF });

    used[u] = 1;

    while (q.size()) {
        auto [v, f] = q.front(); q.pop();

        for (auto &ind : fgraph[v]) {
            auto &e = edges[ind];
            int to = e.to, res = e.res();

            if (used[to] || res < bound) continue;

            p[to] = v;
            pe[to] = ind;
            used[to] = 1;

            if (to == t) {
                pushed = min(f, res);
                break;
            }

            q.push({ to, min(f, res) });
        }
    }

    if (pushed)
        augment(pushed);

    return pushed;
}

// Algorithm: Dinic Algorithm
// Complexity: O((N^2)M)

vector<int> d;

bool bfs_dinic(int u, int bound) {
    d.assign(sz, INF); d[u] = 0;

    queue<int> q; q.push(u);

    while (q.size()) {
        int v = q.front(); q.pop();

        for (auto &ind : fgraph[v]) {
            auto &e = edges[ind];
            int to = e.to, res = e.res();

            if (d[v] + 1 >= d[to] || res < bound) continue;

            d[to] = d[v] + 1;
            q.push(to);
        }
    }

    return d[t] != INF;
}

vector<int> lst;

int dfs_dinic(int u, int mxf = INF) {
    if (u == t) return mxf;

    int smf = 0;

    for (int i = lst[u]; i < fgraph[u].size(); i++) {
        int ind = fgraph[u][i];

        auto &e = edges[ind],
            &_e = edges[ind ^ 1];
        int to = e.to, res = e.res();

        if (d[to] == d[u] + 1 && res) {
            int pushed = dfs_dinic(to, min(res, mxf - smf));

            if (pushed) {
                smf += pushed;
                e.flow += pushed;
                _e.flow -= pushed;
            }
        }

        lst[u]++;

        if (smf == mxf)
            return smf;
    }

    return smf;
}

int dinic(int u) {
    int pushed = 0;

    for (int bound = 1ll << 30; bound; bound >>= 1) {
        while (true) {
            bool bfs_ok = bfs_dinic(u, bound);
            if (!bfs_ok) break;

            lst.assign(sz, 0);

            while (true) {
                int dfs_pushed = dfs_dinic(u);
                if (!dfs_pushed) break;

                pushed += dfs_pushed;
            }
        }
    }

    return pushed;
}

// Algorithm: Maximum Flow Of Minimum Cost (SPFA)
// Complexity: ...


vector<int> d;
vector<int> p;
vector<int> pe;

void augment(int pushed) {
    int cur = t;
    while (cur != s) {
        auto &e = edges[pe[cur]],
            &_e = edges[pe[cur] ^ 1];
        e.flow += pushed;
        _e.flow -= pushed;
        cur = p[cur];
    }
}

int bfs_spfa(int u, int flow = INF) {
    d.assign(sz, INF); d[u] = 0;
    p.assign(sz, -1);
    pe.assign(sz, -1);

    queue<pair<int, int>> q; q.push({ u, flow });
    vector<int> in_q(sz, 0); in_q[u] = 1;

    int pushed = 0;

    while (q.size()) {
        auto [v, f] = q.front(); q.pop();

        in_q[v] = 0;

        if (v == t) {
            pushed = f;
            break;
        }

        for (auto &ind : fgraph[v]) {
            auto &e = edges[ind];
            int to = e.to, res = e.res(),
                w = e.weight;

            if (d[v] + w >= d[to] || !res) continue;
            
            d[to] = d[v] + w;
            p[to] = v;
            pe[to] = ind;

            if (!in_q[to]) {
                in_q[to] = 1;
                q.push({ to, min(f, res) });
            }
        }
    }

    if (pushed)
        augment(pushed);

    return pushed;
}
