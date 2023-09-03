#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <stack>

struct Node {
    using _Node = const Node &;
    
    double x, y;

    // Node(double _x, double _y) {
    //     this->x = _x;
    //     this->y = _y;
    // }

    // Node() {
    //     *this = Node(0, 0);
    // }

    Node operator-() const {
        return {-x, -y};
    }

    Node operator+(_Node n) const {
        return {x + n.x, y + n.y};
    }

    Node operator-(_Node n) const {
        return *this + -n;
    }

    Node operator+=(_Node n) {
        return *this = *this + n;
    }

    Node operator-=(_Node n) {
        return *this = *this - n;
    }

    double get() {
        return y / x;
    }

    double operator*(_Node n) const {
        return x * n.y - y * n.x;
    }

    double abs() const {
        return sqrt(x * x + y * y);
    }

    Node operator*(int k) const {
        return {x * k, y * k};
    }

    friend Node operator*(int k, _Node n) {
        return n * k;
    }

    bool operator<(_Node n) const {
        // return x == n.x ? y < n.y : x < n.x;
        return (x < n.x) || (!(n.x < x) && (y < n.y));
    }
};

const double PI = acos(-1);

int n;
double l, h, r;
std::vector<Node> a;

void P3829() {
    using _Node = const Node &;
    scanf("%d%lf%lf%lf", &n, &h, &l, &r);
    l /= 2;
    l -= r;
    h /= 2;
    h -= r;
    for (int i = 0; i < n; i++) {
        double x, y, th;
        scanf("%lf%lf%lf", &x, &y, &th);
        Node v1, v2;
        v1 = {l * cos(th), l * sin(th)};
        v2 = {h * -sin(th), h * cos(th)};
        Node center = {x, y};
        for (double i = -1; i < 2; i+= 2) {
            for (double j = -1; j < 2; j += 2) {
                a.push_back(center + i * v1 + j * v2);
            }
        }
    }
    std::sort(a.begin(), a.end());
    auto cmp = [](_Node _x, _Node _y) {
        Node _n = a[0];
        Node __x = _x - _n;
        Node __y = _y - _n;
        double k1 = __x.get(), k2 = __y.get();
        return k1 < k2 ||
            !(k2 < k1) && _x < _y;
    };
    std::sort(a.begin() + 1, a.end(), cmp);
    std::stack<Node> s;
    s.push(a[0]);
    for (int i = 1; i < n * 4; i++) {
        while (s.size() > 1) {
            Node t = s.top();
            s.pop();
            Node v1 = t - s.top();
            Node v2 = a[i] - t;
            if (v1 * v2 > 0) {
                s.push(t);
                break;
            }
        }
        s.push(a[i]);
    }
    double ans = 2 * PI * r;
    for (Node now = a[0]; !s.empty(); ) {
        ans += (now - s.top()).abs();
        now = s.top();
        s.pop();
    }
    printf("%.2lf", ans);
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P3829();
    return 0;
}