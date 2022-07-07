#include <cstdio>
#include <queue>

const int maxn = 2e5 + 8;
struct Block {
    int l, r;
}b[maxn];

int a[maxn], cnt;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    std::queue<Block> q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if (i == 1) b[cnt] = (Block) {1, 1};
        if (a[i] == a[i - 1]) b[cnt].r++;
        else cnt++, b[cnt].l = b[cnt].r = i;
    }
    for (int i = 0; i <= cnt; i++) {
        q.push(b[i]);
    }
    while (!q.empty()) {
        int m = q.size();
        for (int i = 0; i < m; i++) {
            Block x = q.front();
            q.pop();
            
        }
    }
}