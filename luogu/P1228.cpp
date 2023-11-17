#include <iostream>
#include <ostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::ostream;

struct Node {
    int x, y;
    int &operator[](int i) {
        return i ? y : x;
    }

    bool operator()(const Node &p, const Node &q) const {
        return x >= p.x && x <= q.x && y >= p.y && y <= q.y;
    }

    Node operator+(const Node &b) const {
        return {x + b.x, y + b.y};
    }

    Node operator/(int k) const {
        return {x / k, y / k};
    }

    bool operator==(const Node &b) const {
        return x == b.x && y == b.y;
    }

    friend ostream &operator<<(ostream &out, const Node &a) {
        return out << a.x << " " << a.y;
    }
} g;

vector<vector<int>> a, b;

int k, u, v, n;

void dfs(const Node &p, const Node &q, int t = 0) {
    Node mid = (p + q) / 2;
    Node next[5] = {
        {},
        mid,
        mid + Node{1, 0},
        mid + Node{0, 1},
        mid + Node{1, 1},
    };
    if (q.x - p.x == 1) {
        if (g(p, q)) {
            int pos;
            for (pos = 1; pos <= 4; pos++) {
                if (next[pos] == g) break;
            }
            cout << next[5 - pos] << " " << pos << "\n";
            b.push_back({next[5 - pos].x, next[5 - pos].y, pos});
        } else {
            cout << next[5 - t] << " " << t << "\n";
            b.push_back({next[5 - t].x, next[t].y, t});
        }
        return;
    }
    Node nt[5][2] = {
        {},
        {p, mid},
        {{mid.x + 1, p.y}, {q.x, mid.y}},
        {{p.x, mid.y + 1}, {mid.x, q.y}},
        {next[4], q}
    };
    if (g(p, q)) {
        int kx = u > mid.x, ky = v > mid.y;
        int pos = 1 + kx + ky * 2;
        
        for (int i = 1; i <= 4; i++) {
            dfs(nt[i][0], nt[i][1], i);
        }
        cout << next[5 - pos] << " " << pos << "\n";
        b.push_back({next[5 - pos].x, next[5 - pos].y, pos});
    } else {
        for (int i = 1; i <= 4; i++) {
            dfs(nt[i][0], nt[i][1], i == t ? t : i);
        }
        cout << next[5 - t] << " " << t << "\n";
        b.push_back({next[5 - t].x, next[5 - t].y, t});
    }
}

void P1228() {
    cin >> k >> u >> v;
    n = 1 << k;
    g = {u, v};
    a.assign(n + 2, vector<int>(n + 2, 0));
    dfs({1, 1}, {n, n});

    for (auto i : b) {
        int x = i[0], y = i[1];
        a[x][y] = i[2];
        // if (i[2] == 1) {
        //     a[x - 1][y] = a[x][y - 1] = 1;
        // } 
        // if (i[2] == 2) {
        //     a[x + 1][y] = a[x][y - 1] = 2;
        // }
        // if (i[2] == 2) {
        //     a[x - 1][y] = a[x][y + 1] = 3;
        // }
        // if (i[2] == 3) {
        //     a[x + 1][y] = a[x][y + 1] = 4;
        // }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    P1228();
    return 0;
}