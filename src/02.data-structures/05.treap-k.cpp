// Theme: Treap With Segments

// Node
struct node_k {
    int key, priority, size;
    node_k *left = nullptr, *right = nullptr;
    node_k(int key, int priority = INF) :
        key(key),
        priority(priority == INF ? dist(reng) : priority),
        size(1) { }
    friend int sz(node_k *nd) { return nd ? nd->size : 0ll; }
    void upd() { size = sz(left) + sz(right) + 1; }
};

// Treap
struct treap_k {
    node_k *root = nullptr;
    treap_k() { }
    treap_k(int key, int priority = INF) : root(new node_k(key, priority)) { }
    treap_k(node_k *rt) : root(rt) { }
    treap_k(const treap_k &tr) : root(tr.root) { }

    // Complexity: O(log(N))
    pair<treap_k, treap_k> split_k(int k) {
        auto res = split_k(root, k);
        return { treap_k(res.ff), treap_k(res.ss) };
    }
    pair<node_k *, node_k *> split_k(node_k *rt, int k) {
        if (!rt) return { nullptr, nullptr };
        if (sz(rt) <= k) return { rt, nullptr };
        if (sz(rt->left) + 1 <= k) {
            auto [rt1, rt2] = split_k(rt->right, k - sz(rt->left) - 1);
            rt->right = rt1;
            rt->upd();
            return { rt, rt2 };
        }
        else {
            auto [rt1, rt2] = split_k(rt->left, k);
            rt->left = rt2;
            rt->upd();
            return { rt1, rt };
        }
    }

    // Complexity: O(log(N))
    treap_k merge_k(const treap_k &tr) {
        root = merge_k(root, tr.root);
        return *this;
    }
    node_k *merge_k(node_k *rt1, node_k *rt2) {
        if (!rt1) return rt2;
        if (!rt2) return rt1;
        if (rt1->priority < rt2->priority) {
            rt1->right = merge_k(rt1->right, rt2);
            rt1->upd();
            return rt1;
        }
        else {
            rt2->left = merge_k(rt1, rt2->left);
            rt2->upd();
            return rt2;
        }
    }
};