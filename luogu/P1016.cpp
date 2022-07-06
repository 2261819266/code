#include <cstdio>

struct youzhan {
    double juli;
    double jusyg;
    double jiage;
    /* data */
} a[10];

double d1, C, d2, p, d3, fy;
int n, c, d, e;

int main() {
    scanf("%lf%lf%lf%lf%d", &d1, &C, &d2, &p, &n);
    a[0] = (youzhan){0, 0, p};
    for (c = 1; c <= n; c++)
        scanf("%d%d", a[c].juli, &a[c+1].jiage),
            a[c].jusyg = a[c].juli - a[c - 1].juli;
    a[n+1]=(youzhan){d1,d1-a[n].juli,}
    d3 = d2 * C;
    if (d1 <= d3) {
        fy=a[1]
        if (n == 0)
            fy = d1 / d2 * p;
        else {
        }
    } else {
    }
    if (fy)
        printf("%.2lf\n", fy);
    else
        printf("No Solution\n");
}