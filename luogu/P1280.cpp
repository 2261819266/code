#include <cstdio>
#include <vector>
#include <algorithm>

const int maxn = 1e4 + 8;
std::vector<int> a[maxn];
int f[maxn];

void P1280() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[x].push_back(y);
    }

    for (int i = n; i > 0; i--) {
        if (a[i].empty()) f[i] = f[i + 1] + 1;
        else {
            for (auto j : a[i]) {
                f[i] = std::max(f[i], f[i + j]);
            }
        }
    }
    printf("%d\n", f[1]);
}

int main() {
    P1280();
    return 0;
}
