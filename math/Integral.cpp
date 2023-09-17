#include <cstdio>
#include <algorithm>
#include <cmath>

double get_integral(double(*f)(double), double x_min = 0, double x_max = 1, double dx = 0.0001) {
    double ans = 0;
    for (double i = x_min; i < x_max; i += dx) {
        ans += (f(i) + f(i + dx)) / 2 * dx;
    }
    return ans;
}

struct Point {
    double x, y;
    double get_mod() {
        return sqrt(x * x + y * y);
    }

    Point operator+(const Point &b) const {
        return {x + b.x, y + b.y};
    }

    Point operator-() const {
        return {-x, -y};
    }

    Point operator-(const Point &b) const {
        return *this + (-b);
    }
};

double f(double x) {
    // return (Point) {1 + cos(x), -sin(x)}.get_mod();
    return sin(x) / x;
}


int main() {
    double y = get_integral(
        f,
        0, 0.2,
        1e-1
    );
    printf("%.15lf\n", y);
}