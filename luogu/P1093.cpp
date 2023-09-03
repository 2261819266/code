#include <cstdio>
#include <algorithm>

const int maxn = 305;
struct Student {
    int Chinese, math, English, total, name;
} a[maxn];

bool operator<(const Student &x, const Student &y) {
    return x.total == y.total ? x.Chinese == y.Chinese ? x.name < y.name : x.Chinese > y.Chinese : x.total > y.total;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &a[i].Chinese, &a[i].math, &a[i].English);
        a[i].total = a[i].Chinese + a[i].math + a[i].English;
        a[i].name = i + 1;
    }
    std::sort(a, a + n);
    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", a[i].name, a[i].total);
    }
}
