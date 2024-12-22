// Theme: Convex Hull

// Algorithm: Graham Algorithm
// Complexity: O(N*log(N))

auto graham(const vector<vec<int>> &points) {
    vec<int> p0 = points[0];
    
    for (auto p : points)
        if (p.y < p0.y ||
        p.y == p0.y && p.x > p0.x)
            p0 = p;

    for (auto &p : points) {
        p.x -= p0.x;
        p.y -= p0.y;
    }

    sort(all(points), [] (vec<int> &p1, vec<int> &p2) {
        return (p1 ^ p2).z > 0 ||
            (p1 ^ p2).z == 0 && p1.norm() > p2.norm(); });

    vector<vec<int>> hull;
    for (auto &p : points) {
        while (hull.size() >= 2 &&
        (((p - hull.back()) ^ (hull[hull.size() - 1] - hull[hull.size() - 2]))).z >= 0)
            hull.pop_back();
        hull.push_back(p);
    }

    for (auto &p : hull) {
        p.x += p0.x;
        p.y += p0.y;
    }

    return hull;
}