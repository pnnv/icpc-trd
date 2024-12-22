// Theme: 2-SAT

// Algorithm: Adding Edges To 2-SAT

vector<vector<int>> ts_graph;
vector<vector<int>> ts_rgraph;

// Vertex By Var Number 
int to_vert(int x) {
    if (x < 0) {
        return ((abs(x) - 1) << 1) ^ 1;
    }
    else {
        return (x - 1) << 1;
    }
}

// Adding Implication
void add_impl(int a, int b) {
    ts_graph[a].insert(b);
    ts_rgraph[b].insert(a);
}

// Adding Disjunction
void add_or(int a, int b) {
    add_impl(a ^ 1, b);
    add_impl(b ^ 1, a);
}
