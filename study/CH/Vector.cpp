

struct Vector {
    double x, y;
    double getK() {
        return y / x;
    }

    double operator*(const Vector &b) {
        return x * b.y - y * b.x;
    } // x \cdot y
};