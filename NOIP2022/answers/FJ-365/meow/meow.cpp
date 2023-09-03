#include <bits/stdc++.h>
using namespace std;
const int M = 2e6 + 7;
const int N = 1e2 + 7;
int T, n, m, k;
int a[M], b[N << 2], t[M], vis[M];
int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while(T --) {
		memset(b, 0, sizeof (b));
		memset(vis, 0, sizeof(vis));
		scanf("%d%d%d%d", &T, &n, &m, &k);
		for (int i = 1; i <= m; ++ i) {
			scanf("%d", &a[i]);
//			if(b[a[i]])	t[b[a[i]]] = i, b[a[i]] = 0;
//			else	b[a[i]] = i;
		}
		printf("%d\n", n);
		for (int i = 1; i <= m; ++ i) {
			printf("1 1\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
~quit
*/
