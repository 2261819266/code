#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using std::cerr;
using std::vector;

bool St;

int cnt = 0;

void solve() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    cnt = 0;

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
    };

    while (q--) {
        int op, b, c;
        vector<Node> x, y;
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
