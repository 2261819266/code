#include <bits/stdc++.h>
using namespace std;
const int N = 2000010;

int T, n, m, k, a[N], id, d[N], b[610][3], len[610];
int c[30];
int op[N << 1], X[N << 1], Y[N << 1], q[N << 1], hd, tl, ss;
int qq[310][30], hhd[30], ttl[30], CK;

inline int read(){
	int num = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
	return num; 
}

void check(){
	ss = 0;
	for(int i = 1; i <= n; i++)
		hhd[i] = 1, ttl[i] = 0;
	int sum = 0;
	for(int i = 1, ppd; i <= m; i++){
		op[++ss] = 1, X[ss] = c[i];
		qq[c[i]][++ttl[c[i]]] = a[i];
		for(int j = 1; j <= n; j++){
			if(hhd[j] < ttl[j] && qq[j][ttl[j]] == qq[j][ttl[j] - 1] && qq[j][ttl[j]])
				ttl[j] -= 2, sum += 2;
		}
		while(1){
			ppd = 0;
			for(int j = 1; j < n; j++)
				for(int k = j + 1; k <= n; k++){
					if(hhd[j] <= ttl[j] && hhd[k] <= ttl[k] && qq[j][hhd[j]] == qq[k][hhd[k]]){
						hhd[j]++, hhd[k]++, sum += 2;
						ppd = 1, op[++ss] = 2, X[ss] = j, Y[ss] = k;
					}
				}
			if(!ppd) break;
		}
//		printf("%d %d\n", i, sum);
	}
	if(sum == m){
		CK = 1;
		printf("%d\n", ss);
		for(int i = 1; i <= ss; i++){
			printf("%d ", op[i]);
			if(op[i] == 1) printf("%d\n", X[i]);
			else printf("%d %d\n", X[i], Y[i]);
		}
	}
}
void dfs(int x){
	if(x == m + 1){
		check();
		return;
	}
	for(int i = 1; i <= n; i++){
		if(CK) return;
		c[x + 1] = i, dfs(x + 1);
	}
}

int main(){

	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout); 

	T = read(), id = T % 10;
	while(T--){
		n = read(), m = read(), k = read();
		for(int i = 1; i <= m; i++) a[i] = read();
		if(id == 1){
			for(int i = 1; i <= n; i++){
				len[i] = 0;
				for(int j = 1; j <= 2; j++)
					b[i][j] = 0;
			}
			for(int i = 1; i <= n + n - 1; i++)
				d[i] = 0;
			hd = 1, tl = 0;
			for(int i = 1; i <= n - 1; i++)
				q[++tl] = i;
			ss = 0;
			for(int i = 1, j; i <= m; i++){
				if(!d[a[i]]){
					j = q[hd];
					len[j]++;
					b[j][len[j]] = a[i];
					d[a[i]] = j;
					op[++ss] = 1, X[ss] = j; 
					if(len[j] == 2) hd++;
				}
				else{
					if(b[d[a[i]]][1] == a[i]){
						op[++ss] = 1, X[ss] = n;
						op[++ss] = 2, X[ss] = d[a[i]], Y[ss] = n;
						b[d[a[i]]][1] = b[d[a[i]]][2], b[d[a[i]]][2] = 0;
						len[d[a[i]]]--;
						if(len[d[a[i]]] == 1) q[++tl] = d[a[i]];
						d[a[i]] = 0;
					}
					else{
						op[++ss] = 1, X[ss] = d[a[i]];
						b[d[a[i]]][2] = 0, len[d[a[i]]]--;
						if(len[d[a[i]]] == 1) q[++tl] = d[a[i]];
						d[a[i]] = 0;
					}
				}
			}
			printf("%d\n", ss);
			for(int i = 1; i <= ss; i++){
				printf("%d ", op[i]);
				if(op[i] == 1) printf("%d\n", X[i]);
				else printf("%d %d\n", X[i], Y[i]);
			}
		}
		else{
			CK = 0;
			dfs(0);
		}
	}
	
	return 0;
}
