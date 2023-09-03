#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int M = 1e6 + 7;

int a[M], n, m, k, T;
int sta1[M], sta2[M];

int main () {
	freopen ("meow.in", "r", stdin);
	freopen ("meow.out", "w", stdout);
	scanf ("%d", &T);
	while (T --) {
		scanf ("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= m; i ++) {
			scanf ("%d", &a[i]);
		}
		if (n == 2) {
			int top1 = 0, top2 = 0, siz1 = 0, siz2 = 0, gr1 = 0, gr2 = 0, ans = 0;
			for (int i = 1; i <= m; i ++) {
				if (!siz1) {
					ans ++;
					top1 ++;
					sta1[top1] = a[i];
					siz1 ++;
				}
				else if (!siz2) {
					ans ++;
					top2 ++;
					sta2[top2] = a[i];
					siz2 ++;
				}
				else if (a[i + 1] == sta1[top1]) {
					i ++;
					top2 ++;
					sta2[top2] = a[i];
					siz2 ++;
					top1 --;
					siz1 --;
					ans += 2;
				}
				else if (a[i + 1] == sta2[top2]) {
					ans += 2;
					i ++;
					top1 ++;
					sta1[top1] = a[i];
					siz1 ++;
					top2 --;
					siz2 --;
				}
				else if (a[i] == sta1[gr1]) {
					gr1 ++;
					ans += 2;
					siz1 --;
				}
				else if (a[i] == sta2[gr2]) {
					gr2 ++;
					ans += 2;
					siz2 --;
				}
			}
			top1 = 0, top2 = 0, siz1 = 0, siz2 = 0, gr1 = 0, gr2 = 0;
			printf ("%d\n", ans);
			for (int i = 1; i <= m; i ++) {
				if (!siz1) {
					printf ("1 1\n");
					top1 ++;
					sta1[top1] = a[i];
					siz1 ++;
				}
				else if (!siz2) {
					printf ("1 2\n");
					top2 ++;
					sta2[top2] = a[i];
					siz2 ++;
				}
				else if (a[i + 1] == sta1[top1]) {
					printf ("1 2\n");
					i ++;
					top2 ++;
					sta2[top2] = a[i];
					siz2 ++;
					top1 --;
					siz1 --;
					printf ("1 1\n");
				}
				else if (a[i + 1] == sta2[top2]) {
					printf ("1 1\n");
					i ++;
					top1 ++;
					sta1[top1] = a[i];
					siz1 ++;
					top2 --;
					siz2 --;
					printf ("1 1\n");
				}
				else if (a[i] == sta1[gr1]) {
					gr1 ++;
					printf ("1 2\n");
					printf ("2 1 2\n");
					siz1 --;
				}
				else if (a[i] == sta2[gr2]) {
					gr2 ++;
					printf ("1 1\n");
					printf ("2 1 2\n");
					siz2 --;
				}
			}
		}
	}
}
