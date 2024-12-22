// Theme: Segment Tree

struct segtree {
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

    // Complexity: O(log(n))
    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    // Complexity: O(log(n))
    int sum(int l, int r, int x, int lx, int rx) {
        if (l <= lx && rx <= r) return tree[x];
        if (l >= rx || r <= lx) return 0;
        int m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) +
            sum(l, r, 2 * x + 2, m, rx);
    }
    int sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};