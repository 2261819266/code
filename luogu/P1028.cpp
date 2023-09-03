#include <cstdio>
#define ll long long

const int maxn = 1005;
ll a[maxn], n;

ll f(int x) {
    ll ans = 1;
    if (x == 1) return ans;
    if (a[x]) return a[x];
    for (int i = 1; i <= x / 2; i++) {
        ans += f(i);
    }
    return a[x] = ans;
}

int main() {
    scanf("%lld", &n);
    printf("%lld", f(n));
}