#include <cstdio>
#include <vector>

const int maxn = 1001;
std::vector<int> g[maxn];

void Link(int x, int y) {
    g[x].push_back(y);
    // g[y].push_back(x);
}

int x, y, n;
int main() {
    scanf("%d", &n);
    for (int c = 1; c < n; c++)
        scanf("%d%d", &x, &y), Link(x, y);
        printf("");
}