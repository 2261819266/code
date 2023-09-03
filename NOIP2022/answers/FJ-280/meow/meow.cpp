#include <bits/stdc++.h>
using namespace std;
const int N = 307, M = 2e6 + 7, Q = 1024;
int n, m;
namespace Sub1 {

int stk[N][2], p[N << 1], emp[N << 1], c;
void Solve() {
	scanf("%d %d %*d", &n, &m);
	for(int i = 1; i <= n - 1; ++i) emp[++c] = i;
	for(int i = 1, x; i <= m; ++i) {
		scanf("%d", &x);
		if(!p[x]) {
			p[x] = emp[c--];
			stk[p[x] % Q][p[x] > Q] = x;
			printf("1 %d\n", p[x] % Q);
			if(p[x] <= Q) emp[++c] = p[x] + Q;
		} else if(p[x] > Q) {
			emp[++c] = p[x];
			stk[p[x] - Q][1] = 0;
			printf("1 %d\n", p[x] - Q);
			p[x] = 0;
		} else if(stk[p[x]][1]) {
			emp[++c] = p[x] + Q;
			p[stk[p[x]][0] = stk[p[x]][1]] = p[x];
			stk[p[x]][1] = 0;
			printf("1 %d\n2 %d %d\n", n, p[x], n);
			p[x] = 0;
		} else {
			emp[++c] = p[x];
			stk[p[x]][0] = 0;
			printf("1 %d\n", p[x]);
			p[x] = 0;
			
		}
	}
}

}
int main() {
	freopen("meow.in", "r", stdin), freopen("meow.out", "w", stdout);
	int T;
	scanf("%d", &T);
	if(T % 10 == 1) while(T--) Sub1::Solve();
//	if(T % 10 == 2) while(T--) Sub2::Solve();
	return 0;
}
