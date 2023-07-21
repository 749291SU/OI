struct Vec {
    double x, y;
    Vec() { }
    Vec(double x, double y) : x(x), y(y) { }   

    Vec operator + (const Vec& rhs) const { return Vec(x + rhs.x, y + rhs.y); }
    Vec operator - (const Vec& rhs) const { return Vec(x - rhs.x, y - rhs.y); }
    Vec operator * (double b) const { return Vec(x * b, y * b); }
    Vec operator / (double b) const { return Vec(x / b, y / b); }
 
    Vec &operator += (const Vec& rhs) { x += rhs.x; y += rhs.y; return *this; }
    Vec &operator -= (const Vec& rhs) { x += rhs.x; y += rhs.y; return *this; }
    Vec &operator *= (double b) { x *= b; y *= b; return *this; }
    Vec &operator /= (double b) { x /= b; y /= b; return *this; }
    
    Vec norm() { return (*this) /= mod(); }
    Vec norm_n() { return Vec(x / mod(), y / mod()); }
    Vec rotate_90() { double tmp = x; x = y; y = -tmp; return *this; }

    double inner(const Vec& rhs) { return x * rhs.x + y * rhs.y; }
    double cross(const Vec& rhs) { return x * rhs.y - y * rhs.x; }
    double modSqu() { return x * x + y * y; }
    double mod() { return std::sqrt(modSqu()); }
};

typedef std::pair<Vec, double> PII;

inline Vec intersec(Vec s1, Vec v1, Vec s2, Vec v2) {
    double t = v2.cross(s1 - s2) / v1.cross(v2);
    return s1 + v1 * t;
}

inline PII circumCir(Vec v1, Vec v2, Vec v3) {
    Vec cir = intersec((v1 + v2) / 2, (v2 - v1).rotate_90(), (v2 + v3) / 2, (v2 - v3).rotate_90()); 
    return { cir, (cir - v1).modSqu() };
}

inline bool in_circle(PII& cir, Vec& p) {
    return (p - cir.first).modSqu() <= cir.second;
}
