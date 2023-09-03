#include <cstdio>
#include <iostream>
#include <map>
#include <string>

const int maxn = 20000 + 10;
std::map<std::string, std::string> a;

void init(std::string s) { a[s] = s; }

std::string find_fa(std::string s) {
    if (s != a[s])
        a[s] = find_fa(a[s]);
    return a[s];
}

void union_fa(std::string x, std::string y) {
    std::string b = find_fa(x), c = find_fa(y);
    if (b != c)
        a[c] = b;
}

bool p_z(std::string x, std::string y) { return (find_fa(x) == find_fa(y)); }

int main() {
    int n, m, k, c, d, e;
    scanf("%d%d%d", &n, &m);
    std::string s1, s2;
    for (c = 0; c < n; c++)
        std::cin >> s1, init(s1);
    for (c = 0; c < m; c++)
        std::cin >> s1 >> s2, union_fa(s1, s2);
    scanf("%d", &k);
    for (c = 0; c < k; c++)
        std::cin >> s1 >> s2, printf("%s", p_z(s1, s2) ? "Yes." : "No.");
}