#include <cstdio>
#include <cstring>

const int maxn = 2e4 + 1;

struct Sentence {
    int speaker;
    bool k;
    int who;
    bool is;
    int day;
} a[maxn];
int n, m, q, now;

char s[21][100];

int find(const char *str) {
    for (int i = 0; i < n; i++) {
        if (strcmp(str, s[i]) == 0) return i;
    }
    return -1;
}

const char weekDay[7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < q; i++) {
        char sp[100];
        scanf("%s", sp);
        sp[strlen(sp) - 1] = 0;
        int speaker = find(sp);
        while (true) {
            char word[100];
            scanf("%s", word);
            bool k = false;
            if (word[strlen(sp) - 1] == '.') k = true, word[strlen(sp) - 1] = 0;
            if (strcmp(word, "guilty") == 0) now++;
        }
    }
}
