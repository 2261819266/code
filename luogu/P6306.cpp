#include <cstdio>
#include <map>
#define ll long long

std::map<ll, int> a;

const int maxn = 1e7 + 8;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        ll x;
        scanf("%lld", &x);
        a[x]++;
        if (a[x] == k) a.erase(x);
    }
    for (auto i = a.begin(); i != a.end(); i++) {
        printf("%lld", i->first);
    }
    return 0;
}