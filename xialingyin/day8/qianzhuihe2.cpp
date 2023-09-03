#include <cstdio>
#include <numeric>
#include<functional>
int cmp(int a,int b){
    return a-b;
}
int a[100], b[100], c, d, n;
int main() {
    scanf("%d", &n);
    for (c = 1; c <= n; c++)
        scanf("%d", &a[c]);
    std::partial_sum(a + 1, a + n + 1, b+1,cmp);
    for (c = 1; c <= n; c++)
        printf("%d ", b[c]);
}