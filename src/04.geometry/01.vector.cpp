// Theme: Methematical 3-D Vector

template <typename T>
struct vec {
    T x, y, z;
    vec(T x = 0, T y = 0, T z = 0) : x(x), y(y), z(z) { }
    vec<T> operator+(const vec<T> &v) const {
        return vec<T>(x + v.x, y + v.y, z + v.z);
    }
    vec<T>operator-(const vec<T> &v) const {
        return vec<T>(x - v.x, y - v.y, z - v.z);
    }
    vec<T>operator*(T k) const {
        return vec<T>(k * x, k * y, k * z);
    }
    friend vec<T> operator*(T k, const vec<T> &v) {
        return vec<T>(v.x * k, v.y * k, v.z * k);
    }
    vec<T> operator/(T k) {
        return vec<T>(x / k, y / k, z / k);
    }
    T operator*(const vec<T> &v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    vec<T> operator^(const vec<T> &v) const {
        return { y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x };
    }
    auto operator<=>(const vec<T> &v) const = default;
    bool operator==(const vec<T> &v) const = default;
    T norm() const {
        return x * x + y * y + z * z;
    }
    double abs() const {
        return sqrt(norm());
    }
    double cos(const vec<T> &v) const {
        return ((*this) * v) / (abs() * v.abs());
    }
    friend ostream &operator<<(ostream &out, const vec<T> &v) {
        return out << v.x << sp << v.y << sp << v.z;
    }
    friend istream &operator>>(istream &in, vec<T> &v) {
        return in >> v.x >> v.y >> v.z;
    }
};