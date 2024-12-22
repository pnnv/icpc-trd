// Theme: Planimetry Objects

// Point
template <typename T>
struct point {
    T x, y;

    point() : x(0), y(0) { }
    point(T x, T y) : x(x), y(y) { }
};


// Rectangle
template <typename T>
struct rectangle {
    point<T> ld, ru;

    rectangle(const point<T> &ld, const point<T> &ru) :
        ld(ld), ru(ru) { }
};