#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>

const int maxn = 5005;

struct node {
	int x;
	int y;
} a[maxn];
bool b[maxn];
double min[maxn], w[maxn][maxn];

double f(int xx, int yy) {
	if (!w[xx][yy]) {
		double x = a[xx].x - a[yy].y;
		double y = a[xx].y - a[yy].y;
		w[xx][yy] = sqrt(x * x + y * y);
	}
	return w[xx][yy];
}

int main() {
	freopen("transport.in", "r", stdin);
//	freopen("transport.out", "w", stdout);
	int n;
	double mst = 0;
	scanf("%d", &n);
	for (int c = 1; c <= n; c++)
		min[c] = 0x7fffffffff;
	min[1] = 0;
	for (int c = 1; c <= n; c++) {
		scanf("%d%d", &a[c].x, &a[c].y);
	}
	for (int c = 1; c <= n; c++) {
		int k = 1;
		for (int d = 1; d <= n; d++) {
			if (!b[c] && min[d] < min[k]) {
				k = d;
			}
		}
		b[c] = true;
		mst += min[k];
		for (int d = 1; d <= n; d++) {
			if (!b[d] && f(k, d) < min[d]) {
				min[d] = f(k, d);
			}
		}
	}
	printf("%.2lf", mst);
}
