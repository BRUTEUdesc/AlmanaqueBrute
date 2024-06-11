template <typename T>
struct point {
    T x, y;
    point(T _x = 0, T _y = 0) : x(_x), y(_y) {}

    using p = point;

    p operator*(const T o) { return p(o * x, o * y); }
    p operator-(const p o) { return p(x - o.x, y - o.y); }
    p operator+(const p o) { return p(x + o.x, y + o.y); }
    T operator*(const p o) { return x * o.x + y * o.y; }
    T operator^(const p o) { return x * o.y - y * o.x; }
    bool operator<(const p o) const { return (x == o.x) ? y < o.y : x < o.x; }
    bool operator==(const p o) const { return (x == o.x) and (y == o.y); }
    bool operator!=(const p o) const { return (x != o.x) or (y != o.y); }

    T dist2(const p o) {
        T dx = x - o.x, dy = y - o.y;
        return dx * dx + dy * dy;
    }

    friend ostream &operator<<(ostream &out, const p &a) {
        return out << "(" << a.x << "," << a.y << ")";
    }
    friend istream &operator>>(istream &in, p &a) { return in >> a.x >> a.y; }
};

using pt = point<ll>;