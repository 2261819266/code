#include <cstdio>

const int maxn = 35;
int a[maxn], b[maxn];
int u[maxn], v[maxn];
bool dat[10];
int n = 0, m;
__int128_t ans = 1;

template<typename t>
void print(t x) {
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

void solve(int x) {
    dat[x] = true;
    for (int i = 0; i < m; i++) {
        if (u[i] == x && !dat[v[i]]) {
            solve(v[i]);
        }
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    char c;
    while ((c = getchar())!=' ') {
        a[n++] = c - '0';
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d", u + i, v + i);
    }
    for (int i = 0; i < n; i++) {
        solve(a[i]);
        for (int j = 0; j < 10; j++) {
            if (dat[j]) dat[j] = false, b[i]++;
        }
        ans *= b[i];
    }
    print(ans);
}