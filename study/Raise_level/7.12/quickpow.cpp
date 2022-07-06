#include <cstdio>
#include <ctime>
#define ll long long

const int mod = 1e9 + 7;

ll qpow(ll bsc, ll y) {
    ll ret = 1;
    while(y) {
        if (y & 1) ret =  ret * bsc % mod;
        bsc = bsc * bsc % mod;
        y >>= 1;
    }
    return ret;
}

ll pow(ll x, ll y) {
    ll ret = 1;
    for (int i = 0; i < y; i++) ret = ret * x % mod;
    return ret;
}

int main(int argc, char const *argv[]) {
    LOCALfo
    ll x, y;
    scanf("%lld%lld", &x, &y);
    int t = clock(), t1, t2;
    printf("%lld\n", qpow(x, y));
    t1 = clock();
    printf("time used : %d ms\n", t1 - t);
    printf("%lld\n", pow(x, y));
    t2 = clock();
    printf("time used : %d ms\n", t2 - t1);
    return 0;
}
