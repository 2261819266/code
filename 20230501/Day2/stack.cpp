#include <cstdio>
#include <stack>
#include <map>
#include <string>
#include <utility>

const int maxn = 2e5 + 8;
std::stack<int> a[maxn];
std::map<std::string, int> map;

void P2_3() {
    int n, m;
    scanf("%d%d", &n, &m);
    map["push"] = 1;
    map["pop"] = 2;
    map["put"] = 3;
    for (int j = 0; j < m; j++) {
        int k, x, y, z;
        char s[10];
        scanf("%s%d%d", s, &x, &y);
        k = map[s];
        if (k == 1) {
            scanf("%d", &z);
            for (int i = 0; i < x; i++) {
                a[z].push(y);
            }
        }
        if (k == 2) {
            int end;
            for (int i = 0; i < x; i++) {
                end = a[y].top();
                a[y].pop();
            }
            printf("%d\n", end);
        }
        if (k == 3) {
            while (!a[x].empty()) {
                a[y].push(a[x].top());
                a[x].pop();
            }
        }
    }
}

int main() {
#ifndef LOCAL
    #define fo(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
    fo(stack)
#endif
    P2_3();
    return 0;
}
