// Theme: Graph Traversing

vector<vector<int>> graph;
vector<int> used;

// Algorithm: Depth-First Search (Adjacency List)
// Complexity: O(N + M)

void dfs(int cur, int p = -1) {
    used[cur] = 1;

    for (auto &to : graph[cur]) {
        if (to == p || used[to]) continue;
        dfs(to, cur);
    }
}

// Algorithm: Breadth-First Search (Adjacency List)
// Complexity: O(N + M)

void bfs(int u) {
    queue<int> q; q.push(u);

    while (q.size()) {
        int cur = q.front(); q.pop();

        for (auto &to : graph[cur]) {
            if (used[to]) continue;
            q.push(to);
        }
    }
}