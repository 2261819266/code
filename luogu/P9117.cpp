#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using std::cerr;
using std::vector;
using std::cin;

bool St;


void solve() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    static int cnt = 0;

    struct Node {
        int col, time;
        Node operator=(int c) {
            col = c;
            time = ++cnt;
            return *this;
        }

        bool operator<(const Node &node) const {
            return time < node.time;
        }

        operator int() const {
            return col;
        }
    };
    vector<Node> x(n), y(m);

    while (q--) {
        int op, b, c;
        cin >> op >> b >> c;
        (op ? y : x)[b - 1] = c;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", std::max(x[i], y[j]));
        }
        putchar(10);
    }
}

void P9117() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}

bool Ed;

int main() {
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
    P9117();
	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
    return 0;
}
