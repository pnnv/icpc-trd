// Theme: Shortest Paths

int sz;

vector<edge> edges;
vector<vector<int>> graph;

// Algorithm: Dijkstra Algorithm
// Complexity: O(M*log(N))

vector<int> d;
vector<int> p;

void dijkstra(int u) {
    d.assign(sz, INF); d[u] = 0;
    p.assign(sz, -1);

    priority_queue<pair<int, int>> q;
    q.push({ 0, u });

    while (q.size()) {
        int dist = -q.top().ff, v = q.top().ss; q.pop();

        if (dist > d[v]) continue;

        for (auto &ind : graph[v]) {
            int to = v ^ edges[ind].u ^ edges[ind].v,
                w = edges[ind].w;
            if (d[v] + w < d[to]) {
                d[to] = d[v] + w;
                p[to] = v;
                q.push({ -d[to], -to });
            }
        }
    }
}

// Algorithm: Shortest Path Faster Algorithm
// Complexity: ...

vector<int> d;

void bfs_spfa(int u) {
    d.assign(sz, INF); d[u] = 0;

    queue<int> q; q.push(u);
    vector<int> in_q(sz, 0); in_q[u] = 1;

    while (q.size()) {
        auto [v, f] = q.front(); q.pop();

        in_q[v] = 0;

        for (auto &ind : graph[v]) {
            int to = v ^ edges[ind].u ^ edges[ind].v,
                w = edges[ind].w;
            if (d[v] + w < d[to]) {
                d[to] = d[v] + w;
                if (!in_q[to]) {
                    in_q[to] = 1;
                    q.push( to );
                }
            }
        }
    }
}

// Algorithm: Belman-Ford Algorithm
// Complexity: (N*M)

vector<int> d;

void bfa(int u) {
    d.assign(sz, INF); d[u] = 0;

    for (;;) {
        bool any = false;

        for (auto &e : edges) {
            if (d[e.u] != INF && d[e.u] + e.w < d[e.v]) {
                d[e.v] = d[e.u] + e.w;
                any = true;
            }
            if (d[e.v] != INF && d[e.v] + e.w < d[e.u]) {
                d[e.u] = d[e.v] + e.w;
                any = true;
            }
        }

        if (!any) break;
    }
}

// Algorithm: Floyd-Warshall Algorithm
// Complexity: O(N^3)

vector<vector<int>> d;

void fwa() {
    d.assign(sz, vector<int>(sz, INF));

    for (int i = 0; i < sz; i++)
        for (int j = 0; j < sz; j++)
            for (int k = 0; k < sz; k++)
                if (d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}