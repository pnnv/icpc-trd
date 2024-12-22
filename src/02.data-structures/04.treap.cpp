// Theme: Treap (Tree + Heap)

// Node
struct node {
    int key, priority;
    node *left = nullptr, *right = nullptr;
    node(int key, int priority = INF) :
        key(key),
        priority(priority == INF ? dist(reng) : priority) { }
};

// Treap
struct treap {
    node *root = nullptr;
    treap() { }
    treap(int key, int priority = INF) : root(new node(key, priority)) { }
    treap(node *rt) : root(rt) { }
    treap(const treap &tr) : root(tr.root) { }

    // Complexity: O(log(N))
    pair<treap, treap> split(int k) {
        auto res = split(root, k);
        return { treap(res.ff), treap(res.ss) };
    }
    pair<node *, node *> split(node *rt, int k) {
        if (!rt) return { nullptr, nullptr };
        if (rt->key < k) {
            auto [rt1, rt2] = split(rt->right, k);
            rt->right = rt1;
            return { rt, rt2 };
        }
        else {
            auto [rt1, rt2] = split(rt->left, k);
            rt->left = rt2;
            return { rt1, rt };
        }
    }

    // Complexity: O(log(N))
    treap merge(treap tr) {
        root = merge(root, tr.root);
        return *this;
    }
    node *merge(node *rt1, node *rt2) {
        if (!rt1) return rt2;
        if (!rt2) return rt1;
        if (rt1->priority < rt2->priority) {
            rt1->right = merge(rt1->right, rt2);
            return rt1;
        }
        else {
            rt2->left = merge(rt1, rt2->left);
            return rt2;
        }
    }
};