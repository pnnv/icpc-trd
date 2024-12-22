// Maximum Matching

// Algorithm: Kuhn Algorithm
// Complexity: O(|Left Part|^3)

vector<vector<int>> bigraph;
vector<int> used;

vector<int> mt;

bool kuhn(int u) {
    if (used[u]) return false;

    used[u] = 1;

    for (auto &v : bigraph[u]) {
        if (mt[v] == -1 || kuhn(mt[v])) {
            mt[v] = u;
            return true;
        }
    }

    return false;
}