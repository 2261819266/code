#include <cstdio>
#include <algorithm>

const int maxn = 5e3 + 5;

struct Student {
    int number, score;
} a[maxn];

bool operator<(const Student &x, const Student &y) {
    return x.score == y.score ? x.number < y.number : x.score > y.score;
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = (Student) {x, y};
    }
    std::sort(a, a + n);
    int k = std::min((int)(m * 1.5), n);
    int sco = a[k - 1].score;
    int s = 0;
    for (; a[s].score >= sco; s++) ;
    printf("%d %d\n", sco, s);
    for (int i = 0; i < s; i++) {
        printf("%d %d\n", a[i].number, a[i].score);
    }
}