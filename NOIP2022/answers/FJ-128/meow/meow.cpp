#include <bits/stdc++.h>

const int N = 2e6 + 5, K = 1000;

int n, m, k, ins;

int a[N], b[K], up[K], down[K];

int op[N * 2], c1[N * 2], c2[N * 2], tot;

int st[K], top, st1[K], top1;

int t[K][2];

void Push(int x) {
	if (top == 0) {
		b[x] = st1[top1];
		t[b[x]][1] = x;
		top1 --;
	} else {
		b[x] = st[top];
		t[b[x]][0] = x;
		++ top1;
		st1[top1] = st[top];
		-- top;
	}
	op[++ tot] = 1;
	c1[tot] = b[x];
}

//void clear_up(int x) {
//	int bel = b[x];
//}
//void clear_down(int x) {
//	
//}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T --) {
		scanf("%d%d%d", &n, &m, &k);
		ins = tot = 0;
		
		for (int i = 1; i <= m; ++ i) 
			scanf("%d", &a[i]);
			
		for (int i = 1; i < n; ++ i)
			st[i] = n - i;
		top = n - 1;
		
		if (k == 2 * n - 2) {
			for (int i = 1; i <= m; ++ i) {
				if (b[a[i]]) {
					int x = b[a[i]];
					if (t[x][1] == a[i]) {
						op[++ tot] = 1;
						c1[tot] = x;
						st1[++ top1] = x;
						
						b[a[i]] = 0;
						t[x][1] = 0;
					} else {
						op[++ tot] = 1;
						c1[tot] = n;
						op[++ tot] = 2;
						c1[tot] = x;
						c2[tot] = n;
						
						if (t[x][1] == 0)  {
							t[x][0] = 0;
							st[++ top] = x;
						} else {
							t[x][0] = t[x][1];
							t[x][1] = 0;
							st1[++ top1] = x;
						}				
						b[a[i]] = 0;
					}
				} else Push(a[i]);
			}
			printf("%d\n", tot);
			for (int i = 1; i <= tot; ++ i) {
				printf("%d ", op[i]);
				if (op[i] == 1) printf("%d\n", c1[i]);
				else printf("%d %d\n", c1[i], c2[i]);
			}
		} else if (n == 2) {
			for (int i = 1; i <= m; ++ i) {
				if (b[a[i]]) {
					int x = b[a[i]];
//					printf(":%d %d\n", i, x);
					if (t[x][0] == a[i]) {
						if (t[x][1] == 0) {
							op[++ tot] = 1;
							c1[tot] = x;
							t[x][0] = 0;
							b[a[i]] = 0;
							ins --;
						} else {
							int v = (x == 1 ? 2 : 1);
							op[++ tot] = 1;
							c1[tot] = v;
							op[++ tot] = 2;
							c1[tot] = x, c2[tot] = v;
							t[x][0] = t[x][1];
							t[x][1] = 0;
							b[a[i]] = 0;
							ins --;
						}
					} else {
						op[++ tot] = 1;
						c1[tot] = x;
						t[x][1] = 0;
						b[a[i]] = 0;
						ins --;
					}
				} else {
					if (ins == 2) {
						if (a[i] == a[i + 1]) {
							op[++ tot] = 1;
							c1[tot] = 1;
							op[++ tot] = 1;
							c1[tot] = 1;
							++ i;
						} else {
							int v = b[a[i + 1]];
							int vv = (v == 1 ? 2 : 1);
							if (t[v][0] == a[i + 1]) {
								if (t[v][1]) {
									op[++ tot] = 1;
									c1[tot] = v;
									op[++ tot] = 1;
									c1[tot] = vv;
									t[v][0] = t[v][1];
									t[v][1] = a[i];
									op[++ tot] = 2;
									c1[tot] = 1, c2[tot] = 2;
									b[a[i]] = v;
									b[a[i + 1]] = 0;
									++ i;
								} else {
									t[vv][1] = a[i];
									op[++ tot] = 1;
									c1[tot] = vv;
									op[++ tot] = 1;
									c1[tot] = v;
									t[v][0] = 0;
									b[a[i]] = vv;
									b[a[i + 1]] = 0;
									++ i;
								}
							} else {
								op[++ tot] = 1;
								c1[tot] = vv;
								t[vv][0] = a[i];
								op[++ tot] = 1;
								c1[tot] = v;
								t[v][1] = 0;
								b[a[i + 1]] = 0;
								b[a[i]] = vv;
								i ++;
							}
						}
					} else {
						if (ins == 0) {
							op[++ tot] = 1;
							c1[tot] = 1;
							b[a[i]] = 1;
							t[1][0] = a[i];
							ins ++;
						} else {
							int v = (t[1][0] ? 2 : 1);
//							printf("ssss%d\n", v);
							op[++ tot] = 1;
							c1[tot] = v;
							b[a[i]] = v;
							t[v][0] = a[i];
							ins ++;
						}
					}
				}
//				printf("%d\n", i);
//				for (int ii = 1; ii <= 2; ++ ii) {
//					for (int bb = 0; bb <= 1; ++ bb)
//						printf("%d ", t[ii][bb]);
//					puts("");
//				}
			}
			printf("%d\n", tot);
			for (int i = 1; i <= tot; ++ i) {
				printf("%d ", op[i]);
				if (op[i] == 1) printf("%d\n", c1[i]);
				else printf("%d %d\n", c1[i], c2[i]);
			}
		} 
//		else if (n == 3) {
//			
//		}
	}
}
