// Theme: Trie

// Algorithm: Aho-Corasick
// Complexity: O(N)

struct trie {
    // Vertex
    struct vertex {
        vector<int> next;
        bool leaf;
    };

    // Alphabet size
    static const int N = 26;
    // Maximum Vertex Number
    static const int MX = 2e5 + 1;

    // Vertices Vector
    vector<vertex> t;
    int sz;

    trie(): sz(1) {
        t.resize(MX);
        t[0].next.assign(N, -1);
    }

    void add_str(const string &s) {
        int v = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i] - 'a';
            if (t[v].next[c] == -1) {
                t[sz].next.assign(N, -1);
                t[v].next[c] = sz++;
            }
            v = t[v].next[c];
        }
        t[v].leaf = true;
    }
};