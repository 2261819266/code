#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 310;
ll read() {
	ll x = 0, f = 1;
	char c;
	while(!isdigit(c = getchar())) if(c == '-') f = -f;
	do{
		x = x * 10 + c - '0';
	}while(isdigit(c = getchar()));
	return x * f;
}
int T, n, m, k, stk[N][20], op, a[N], top[N], bot[N];
//bool dfs(int t, int s) {
//	if(t > m) {
//		if(top[1] < bot[1] and top[2] < bot[2] and top[3] < bot[3]) return true;
//		if(stk[1][bot[1]] == stk[2][bot[2]]) {
//			++bot[1]; ++bot[2];
//			if(dfs(t, s + 2)) {
//				
//		}
//	}
//}
int main() {
  freopen("meow.in", "r", stdin);
  freopen("meow.out", "w", stdout);
  ios::sync_with_stdio(false);
  T = read();
  while(T--) {
  	n = read(); m = read(); k = read();
  	for(int i = 1; i <= n; ++i) bot[i] = 1;
  	memset(top, 0, sizeof(top));
  	memset(stk, 0, sizeof(stk));
  	op = 0;
  	if(k <= 2 * n - 2) {
  	  for(int i = 1; i <= n; ++i) bot[i] = 1;
  		for(int i = 1; i <= m; ++i) {
  	  	a[i] = read();
  		  int bel = (a[i] + 1) >> 1;
  		  if(stk[bel][top[bel]] == a[i]) {
  		  	++op; --top[bel];
  		  	continue;
				}
				if(stk[bel][bot[bel]] == a[i] and bot[bel] <= top[bel]) {
				  op += 2; ++bot[bel];
				  continue;
				}
				stk[bel][++top[bel]] = a[i];
				++op;
		  }
  	  printf("%d\n", op);
  	  for(int i = 1; i <= n; ++i) bot[i] = 1;
  	  memset(top, 0, sizeof(top));
  	  for(int i = 1; i <= m; ++i) {
  		  int bel = (a[i] + 1) >> 1;
  		  if(stk[bel][top[bel]] == a[i]) {
  		  	printf("1 %d\n", bel); --top[bel];
  		  	continue;
				}
				if(stk[bel][bot[bel]] == a[i] and bot[bel] <= top[bel]) {
				  printf("1 %d\n2 %d %d\n", n, bel, n); ++bot[bel];
				  continue;
				}
				stk[bel][++top[bel]] = a[i];
				printf("1 %d\n", bel);
		  }
		}
		else return 0;
//		else {
//			if(m <= 14) {
//				dfs(1, 1);
//			}
//		}
	}
  return 0;
}

