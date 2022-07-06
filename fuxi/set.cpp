#include <cstdio>
#include <set>

std::set<int> a;
std::set<int>::iterator s;
int b, c, n;

int main() {
    scanf("%d", &n);
    for (c = 0; c < n; c++)
        scanf("%d", &b), a.insert(b);
    for (s = a.begin(); s != a.end(); s++)
        printf("%d ", *s);
}