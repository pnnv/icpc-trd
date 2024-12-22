// Theme: Longest Increasing Subsequence

// Algorithm: Binary Search Algorithm
// Complexity: O(N*log(N))

auto inc_subseq(const vector<int> &a) {
    int n = a.size();
    vector<int> dp(n + 1, INF), pos(n + 1), prev(n), subseq;

    int len = 0;
    dp[0] = -INF;
    pos[0] = -1;

    for (int i = 0; i < n; i++) {
        int j = distance(dp.begin(), upper_bound(all(dp), a[i]));
        if (dp[j - 1] < a[i] && a[i] < dp[j]) {
            dp[j] = a[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            len = max(len, j);
        }
    }

    int p = pos[len];
    while (p != -1) {
        subseq.push_back(a[p]);
        p = prev[p];
    }
    reverse(subseq.begin(), subseq.end());

    return subseq;
}