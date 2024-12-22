// Theme: Segment Tree With Propagation

struct segtree_prop {
    int size;
    vector<int> tree;

    void init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size - 1, 0);
    }

    void build(vector<int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < a.size()) tree[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void build(vector<int> &a) {
        init(a.size());
        build(a, 0, 0, size);
    }
    
    void push(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        tree[2 * x + 1] += tree[x];
        tree[2 * x + 2] += tree[x];
        tree[x] = 0;
    }

    // Complexity: O(log(n))
    void add(int v, int l, int r, int x, int lx, int rx) {
        push(x, lx, rx);
        if (rx <= l || r <= lx) return;
        if (l <= lx && rx <= r) {
            tree[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(v, l, r, 2 * x + 1, lx, m);
        add(v, l, r, 2 * x + 2, m, rx);
    }
    void add(int v, int l, int r) {
        add(v, l, r, 0, 0, size);
    }

    // Complexity: O(log(n))
    int get(int i, int x, int lx, int rx) {
        push(x, lx, rx);
        if (rx - lx == 1) return tree[x];
        int m = (lx + rx) / 2;
        if (i < m) return get(i, 2 * x + 1, lx, m);
        else return get(i, 2 * x + 2, m, rx);
    }
    int get(int i) {
        return get(i, 0, 0, size);
    }
};