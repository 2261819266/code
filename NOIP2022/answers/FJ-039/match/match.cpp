#include <bits/stdc++.h>

#define int unsigned long long

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) (ch == '-') && (f = 1);
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = (a * 10) + (ch - '0');
    f && (a = -a);
}
template <class T, class ...Y> void fr(T &a, Y &...b) { fr(a), fr(b...); }
int fr() { int a; return fr(a), a; }

const int N = 2.5e5;

int n, q, a[N + 10], b[N + 10];

struct OI {
    int RP, score;
} NOIP2022;

signed main() {
    NOIP2022.RP++, NOIP2022.score++;
    freopen("match.in", "r", stdin), freopen("match.out", "w", stdout);
    int ID = fr(); fr(n);
    for (int i = 1; i <= n; i++) fr(a[i]);
    for (int i = 1; i <= n; i++) fr(b[i]);
    fr(q);
    for (int _ = 1, l, r; _ <= q; _++) {
        fr(l, r);
        int ans = 0;
        for (int i = l; i <= r; i++) {
            int mxa = 0, mxb = 0;
            for (int j = i; j <= r; j++) mxa = max(mxa, a[j]), mxb = max(mxb, b[j]), ans += mxa * mxb;
        }
        printf("%llu\n", ans);
    }
    return 0;
}