// Theme: Minimum Spanning Tree

int sz;

vector<edge> edges;
vector<vector<int>> graph;

// Algorithm: Kruskal Algorithm
// Complexity: O(M)

vector<edge> mst;

void kruskal() {
    dsu d(sz);

    auto tedges = edges;
    sort(all(tedges), [] (edge &e1, edge &e2) { return e1.w < e2.w; });

    for (auto &e : tedges) {
        if (d.get(e.u) != d.get(e.v)) {
            mst.push_back(e);
            d.unite(e.u, e.v);
        }
    }
}