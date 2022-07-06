#include <cstdio>
#define ll long long

const char s[2][10] = {"Alice", "Bob"};

int main() {
    ll a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    printf("%s", s[!(a * a > b * c)]);
}