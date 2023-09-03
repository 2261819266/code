#include <cstdio>
#include <set>

std::set<int> a;
std::set<int>::iterator s;
int b, c, n;

int main() {
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%d", &b), a.insert(b);
    // scanf("%d", &b);
    // s = a.find(b);
    // if (s == a.end())
    //     printf("Not Found\n");
    // else
    //     printf("%d\n", *s);
    scanf("%d", &b);
    a.erase(b); //||a.erase(a.find(b));
    for (s = a.begin(); s != a.end(); s++)
        printf("%d ", *s);
    // scanf("%d%d", &b, &c);
    // a.erase(b, a.find(c));
    // for (s = a.begin(); s != a.end(); s++)
    //     printf("%d", *s);
}