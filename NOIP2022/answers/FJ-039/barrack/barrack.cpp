#include <bits/stdc++.h>

using namespace std;

template <class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) (ch == '-') && (f = 1);
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = (a * 10) + (ch - '0');
    f && (a = -a);
}
template <class T, class ...Y> void fr(T &a, Y &...b) { fr(a), fr(b...); }
int fr() { int a; return fr(a), a; }

struct OI {
    int RP, score;
} NOIP2022;

signed main() {
    NOIP2022.RP++, NOIP2022.score++;
    
    return 0;
}