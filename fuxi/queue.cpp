#include <cstdio>
#include <iostream>
#include <queue>

int main() {
    std::queue<int> a;
    a.push(8);
    printf("%d %d %d\n", a.front(), a.back(), a.size());
    a.push(12);
    printf("%d %d %d\n", a.front(), a.back(), a.size());
    a.push(19);
    printf("%d %d %d\n", a.front(), a.back(), a.size());
    a.pop();
    printf("%d %d %d\n", a.front(), a.back(), a.size());
    std::queue<int> b;
    b.push(9);
    b.push(15);
    printf("%d %d %d\n", b.front(), b.back(), b.size());
    a.swap(b);
    printf("a: %d %d %d\nb: %d %d %d\n", a.front(), a.back(), a.size(),
           b.front(), b.back(), b.size());
}