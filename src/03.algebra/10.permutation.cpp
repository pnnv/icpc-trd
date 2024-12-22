// Theme: Permmutations

// Algorithm: Next Lexicological Permutation
// Complexity: O(N)

bool perm(vector<int> &v) {
    int n = v.size();
    
    for (int i = n - 1; i >= 1; i--) {
        if (v[i - 1] < v[i]) {
            reverse(v.begin() + i, v.end());

            int j = distance(v.begin(),
            upper_bound(v.begin() + i, v.end(), v[i - 1]));

            swap(v[i - 1], v[j]);
            return true;
        }
    }
    
    return false;
}