#include <cstdio>
#include <stack>
#include <string.h>

bool ifnumber(char a) { return (a >= '0' && a <= '9'); }

bool ifyunsuanfu(char a) {
    return a == '+' || a == '-' || a == '*' || a == '/';
}

char s;
std::stack<int> a;
int b, c, d, e;
int main() {

    for (scanf("%c", &s); s != '@'; scanf("%c", &s)) {
        if (ifnumber(s)) {
            char ss[1005];
            ss[0] = s;
            for (d = 0; ss[d] != '.';) {
                scanf("%c", &ss[++d]);
            }
            ss[++d] = 0;
            int n = strlen(ss) - 1;
            int sum = 0;
            for (d = 0, e = 1; d < n; d++, e *= 10) {
                sum += (ss[n - d - 1] - '0') * e;
            }
            a.push(sum);
            continue;
        }
        if (ifyunsuanfu(s)) {
            int k2 = a.top();
            a.pop();
            int k1 = a.top();
            a.pop();
            if (s == '+')
                a.push(k1 + k2);
            if (s == '-')
                a.push(k1 - k2);
            if (s == '*')
                a.push(k1 * k2);
            if (s == '/')
                a.push(k1 / k2);
        }
    }
    printf("%d", a.top());
}