#include <bits/stdc++.h>
using namespace std;

const int M = 2010000, K = 700;
int T, n, m, k, a[M];
int state[K], stkid[K], sz[K], inc[K], up[K]; // 1 : Õ»¶¥    -1 : Õ»µ×     0 : Î´³öÏÖ  
set<int> e1, e2; // Ê£1/2¸ö¿ÕÎ» 
struct outt {
	int type, a, b;
//	outt(int type, int a, int b = 0) : type(type), a(a), b(b) {}
} ans[M << 1];
int op;
inline void remove(int color, int x) {
	
//	printf("remove %d %d\n", color, x);
	if (sz[x] == 2 && state[color] == -1) state[up[x]] = -1;
	if (sz[x] == 2) e1.insert(x);
	else e1.erase(e1.find(x)), e2.insert(x);
	sz[x]--, state[color] = stkid[color] = 0;
}
inline void incre(int color, int stk) {
	
//	printf("incre %d %d\n", color, stk);
	
	if (sz[stk] == 1) e1.erase(e1.find(stk)), sz[stk]++, state[color] = 1, stkid[color] = stk;
	else e2.erase(e2.find(stk)), e1.insert(stk), sz[stk]++, state[color] = -1, stkid[color] = stk;
	up[stk] = color;
}
inline void pr(outt x) {
	if (x.type == 1) printf("%d %d\n", x.type, x.a);
	else printf("%d %d %d\n", x.type, x.a, x.b);
}
int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d", &n, &m, &k), op = 0;
		memset(state, 0, sizeof(state)), memset(stkid, 0, sizeof(stkid)), memset(sz, 0, sizeof(sz)), memset(inc, 0, sizeof(inc)), memset(up, 0, sizeof(up));
		for (int i = 0; i < m; i++) scanf("%d", a + i);
		e1.clear(), e2.clear();
		for (int i = 1; i <= n; i++) e2.insert(i);
		for (int i = 0; i < m; i++) {
			
//			printf("==========%d :\n", i);
//			printf("%d %d\n", state[a[i]], stkid[a[i]]);
			
			if (state[a[i]] == 1) {
//				printf("CASEA\n");
				ans[op++] = {1, stkid[a[i]]};
				
//				pr(ans[op - 1]);
				remove(a[i], stkid[a[i]]);
//				state[a[i]] = stkid[a[i]] = 0;		
			} else if (state[a[i]] == -1) {
//				printf("CASEB\n");
				int p = *e2.begin();
				ans[op++] = {1, p}, ans[op++] = {2, p, stkid[a[i]]};
				
//				pr(ans[op - 2]), pr(ans[op - 1]);
				remove(a[i], stkid[a[i]]);
//				state[a[i]] = stkid[a[i]] = 0;
			} else if (!e1.empty()) {
//				printf("CASEC\n");
				int p = *e1.begin();
//				e1.erase(e1.begin());
				ans[op++] = {1, p};
				
//				pr(ans[op - 1]);
//				state[a[i]] = 1, sz[stkid[a[i]] = p]++;
				incre(a[i], p);
			} else if (e2.size() > 1) {
//				printf("CASED\n");
				int p = *e2.begin();
//				e2.erase(e2.begin()), e1.insert(p);
				ans[op++] = {1, p};
				
//				pr(ans[op - 1]);
//				state[a[i]] = -1, sz[stkid[a[i]] = p]++;
				incre(a[i], p);
			} else {
//				printf("warning! : %d\n", i);
				int j = i + 1;
				while (state[a[j]] == 1 && a[j] != a[i]) inc[a[j]] = 1, j++;
				if (a[j] == a[i]) {
					int f = *e2.begin();
					incre(a[i], f), ans[op++] = {1, f};
					for (int k = i + 1; k < j; k++) {
						if (!state[a[k]]) {
							set<int>::iterator qq = e1.begin();
							if (*qq == f) qq++;
							int q = *qq;
							ans[op++] = {1, q};
							incre(a[k], q);
						} else {
							int q = stkid[a[k]];
							ans[op++] = {1, q};
							remove(a[k], q);
						}
					}
					ans[op++] = {1, f};
					remove(a[j], f);
				} else if (!inc[up[stkid[a[j]]]]) {
					int p = stkid[a[j]], ud = up[stkid[a[j]]];
					ans[op++] = {1, p};
					for (int k = i + 1; k < j; k++) {
						if (!state[a[k]]) {
							int q = *e1.begin();
							ans[op++] = {1, q};
							incre(a[k], q);
						} else {
							int q = stkid[a[k]];
							ans[op++] = {1, q};
							remove(a[k], q);
						}
					}
					ans[op++] = {1, *e2.begin()}, ans[op++] = {2, *e2.begin(), p};
					remove(a[j], p), incre(a[i], p), state[ud] = -1;
				} else {
					int p = stkid[a[j]], f = *e2.begin();
					incre(a[i], f), ans[op++] = {1, f};
					for (int k = i + 1; k < j; k++) {
						if (!state[a[k]]) {
							set<int>::iterator qq = e1.begin();
							if (*qq == p) qq++;
							int q = *qq;
							ans[op++] = {1, q};
							incre(a[k], q);
						} else {
							int q = stkid[a[k]];
							ans[op++] = {1, q};
							remove(a[k], q);
						}
					}
					ans[op++] = {1, p};
					remove(a[j], p);
				}
				for (int k = i + 1; k < j; k++) inc[a[k]] = 0;
				i = j;
			}
		}
		printf("%d\n", op);
		for (int i = 0; i < op; i++) pr(ans[i]);
	}
	return 0;
}
