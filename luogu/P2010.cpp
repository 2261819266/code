#include <cstdio>

const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Data {
    int y, m, d;
    Data operator=(int x) {
        y = x / 10000;
        m = x / 100 % 100;
        d = x % 100;
        return *this;
    }
    bool isR() { return !(y % 100 ? y % 4 : y % 400); }
    Data operator++() {
        d++;
        if (d > days[m] && m == 2) {
            if (!isR()) d -= days[m], m++;
            else if (d > days[m] + 1) d -= days[m] + 1, m++;
        }
        else if (d > days[m]) d -= days[m], m++;
        if (m > 12) m -= 12, y++;
        return *this;
    }
    bool isH() {
        char s[10];
        sprintf(s, "%04d%02d%02d", y, m, d);
        for (int i = 0; i < 4; i++) if (s[i] - s[7 - i]) return false;
        return true;
    }
    bool operator!=(const Data &b) { return y != b.y || m != b.m || d != b.d; }
    Data operator++(int) { return ++*this; }
} a, b;

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int l, r;
    scanf("%d%d", &l, &r);
    a = l, b = r;
    b++;
    int ans = 0;
    for (Data i = a; i != b; i++) 
        ans += i.isH();
    printf("%d", ans);
}
