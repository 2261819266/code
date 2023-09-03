#include <cstdio>

const int maxn = 30;
char s[maxn];


void P1061() {
    int start, end, w;
    scanf("%d%d%d%s", &start, &end, &w, s);
    start += 'a' - 1, end += 'a' - 1;
    for (int i = 0; i < 5; i++) {
        if (s[w - 1] < end) s[w - 1]++;
        else {
            int j;
            for (j = w - 2; s[j] == s[j + 1] - 1; j--) {
                if (!j) return;
            }
            s[j]++;
            for (j++; j < w; j++) {
                s[j] = s[j - 1] + 1;
            }
        }
        printf("%s\n", s);
    }
}


int main() {
#ifdef LOCAL
    LOCALfo
#endif
    P1061();
    return 0;
}