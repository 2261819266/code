#include <bits/stdc++.h>
using namespace std;
const int N = 600;
int stk[N][5], tp[N];
int ans[4][N];
inline void Subtask1() {
	int n, m, k, op = 0; scanf("%d%d%d", &n, &m, &k);
	for(int i = 1, x; i <= m; i++) {
		scanf("%d", &x);
		int sid = (x - 1) >> 1;
		if(tp[sid] == 0) {
//			printf("in0, %d %d", sid, x);
			op++;
			ans[0][op] = 1, ans[1][op] = sid + 1;
			stk[sid][++tp[sid]] = x;
		} else if(tp[sid] == 1) {
			if(stk[sid][1] == x) {
//				printf("in1a, %d %d", sid, x);
				op++;
				ans[0][op] = 1, ans[1][op] = sid + 1;
				tp[sid] = 0;
			} else {
//				printf("in1b, %d %d", sid, x);
				op++;
				ans[0][op] = 1, ans[1][op] = sid + 1;
				stk[sid][++tp[sid]] = x;
			}
		} else if(tp[sid] == 2) {
			if(stk[sid][1] == x) {
//				printf("in2a, %d %d %d", sid, x, op);
				op++;
				ans[0][op] = 1, ans[1][op] = n;
				op++;
				ans[0][op] = 2, ans[1][op] = sid + 1, ans[2][op] = n;
//				printf("in2a, %d %d %d", sid, x, op);
				stk[sid][1] = stk[sid][2];
				tp[sid] = 1;
			}
			if(stk[sid][2] == x) {
//				printf("in2b, %d %d", sid, x);
				op++;
				ans[0][op] = 1, ans[1][op] = sid + 1;
				tp[sid] = 1;
			}
		}
	}
	printf("%d\n", op);
	for(int i = 1; i <= op; i++) {
		printf("%d ", ans[0][i]);
		if(ans[0][i] == 1) {
			printf("%d\n", ans[1][i]);
		} else {
			printf("%d %d\n", ans[1][i], ans[2][i]);
		}
	}
}
int main () {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int Tgb, ty; scanf("%d", &Tgb); ty = Tgb % 10;
	while(Tgb--) {
		if(ty == 1) Subtask1();
	}
	return 0; 
}
/*
1
2 4 2
1 2 1 2
*/
