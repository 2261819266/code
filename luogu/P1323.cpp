#include <cstdio>
#include <queue>
#include <stack>
#include <cstring>

const int maxn = 3e7 + 8;

std::priority_queue<int, std::vector<int>, std::greater<int>>q;
int a[maxn];char b[maxn], c[maxn];

void init(int n) {
    q.push(1);
    for (int i = 0; i < n; i++) {
        int x = q.top();
        q.pop();
        q.push(2 * x + 1);
        q.push(4 * x + 5);
        a[i] = x;
    }
}

void del(char *result, const char *str, int m) {
    std::stack<char> s;
    int n = strlen(str);
    for (int i = 0; str[i]; i++) {
        if (s.size() - i == - m) {
            for (; str[i]; i++) {
                s.push(str[i]);
            }
            break;
        }
        while (!s.empty()) {
            if (str[i] > s.top()) s.pop();
            else break;
        }
        s.push(str[i]);
    }
    for (int i = s.size() - 1; i >= 0; i--) {
        result[i] = s.top();
        s.pop();
    }
}

int main() {
#ifdef LOCAL
    LOCALfo
#endif
    int n, m;
    scanf("%d%d", &n, &m);
    init(n);
    char *p = b;
    for (int i = 0; i < n; i++) {
        sprintf(p, "%d", a[i]);
        p += strlen(p);
    }
    del(c, b, m);
    printf("%s\n%s", b, c);
}