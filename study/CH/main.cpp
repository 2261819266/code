#include <cstdio>
#include <algorithm>
#include <stack>
#include <cmath>


const int maxn = 1e5 + 8;
struct Vector {
    double x, y;
    double getK() {
        return y / x;
    }

    double operator*(const Vector &b) const {
        return x * b.y - y * b.x;
    } // x \cdot y

    Vector operator+(const Vector &b) const {
        return {x + b.x, y + b.y};
    }

    Vector operator-(const Vector &b) const {
        return {x - b.x, y - b.y};
    }

    bool operator<(const Vector &b) const {
        return (x < b.x) || (!(b.x < x) && y < b.y);
    }

    double abs() const {
        return sqrt(x * x + y * y);
    }
} a[maxn];

int main() {
#ifdef LOCAL
    LOCALfo
#endif  
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        double x, y;
        scanf("%lf%lf", &x, &y);
        a[i] = {x, y};
    }
    std::sort(a, a + n);
    std::sort(a + 1, a + n, [](const Vector &x, const Vector &y) {
        if ((x - *a).getK() == (y - *a).getK())
            return x < y;
        return (x - *a).getK() < (y - *a).getK();
    });
    std::stack<Vector> s;
    s.push(a[0]);
    for (int i = 1; i < n; i++) {
        while (s.size() > 1) {
            auto x = s.top();
            s.pop();
            auto v1 = x - s.top();
            auto v2 = a[i] - x;
            if (v1 * v2 > 0) {
                s.push(x);
                break;
            }
        }
        s.push(a[i]);
    }
    double ans = 0;
    for (Vector now = a[0]; !s.empty(); ) {
        ans += (now - s.top()).abs();
        now = s.top();
        s.pop();
    }
    printf("%.2lf", ans);
}