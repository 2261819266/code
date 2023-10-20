#include <cstdio>

int a[9], vis[9];

double create(const int *p) {
    return (double) *p / (10 * *(p + 1) + *(p + 2));
}

double f() {
    return create(a) + create(a + 3) - create(a + 6);
}


double (*const func)() = f;

void dfs(int x = 0) {
    
}

void solve() {

}

int main() {
    solve();
    return 0;
}
