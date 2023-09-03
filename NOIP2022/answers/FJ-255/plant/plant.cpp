#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
#define ep emplace_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define fin freopen("in.in","r",stdin);
inline int read() {
	int x=0,v=1,ch=getchar();
	while('0'>ch||ch>'9') {
		if(ch=='-')v = 0;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9') {
		x = x * 10 + (ch^'0');
		ch=getchar();
	}
	return v ? x : -x;
}
const int P = 998244353;
const int MAX = 1010;
void inc(int &x,int y) {
	x += y;
	if(x >= P) x -= P; 
}
char s[MAX][MAX];
int T, id;
int a[MAX][MAX], n, m, C, F;
int up[MAX];

void clr() {
	for(int i=1;i<=n;++i) up[i] = 0;
}
signed main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out","w",stdout);
	T = read();
	id = read();
	while(T--) {
		n = read(), m = read(), C = read(), F = read();
		for(int i=1;i<=n;++i) {
			scanf("%s", s[i] + 1);
			for(int j=1;j<=m;++j) {
				a[i][j] = s[i][j] - '0';
			}
		}
		int ansc = 0, ansf = 0;
		for(int y=m;y>=1;--y) { // meiju y0
			for(int i=1;i<=n;++i) {
				if(a[i][y] == 1) {
					up[i] = 0;
				}else up[i] ++;
			}
			// 2 ~ up[i]
			int sumc = 0, sumf = 0, tf = 0;
			for(int i=n;i>=1;--i) {
				if(up[i] == 0) {
					sumc = 0;
					sumf = 0;
					tf = 0;
				}else {
					int aa = up[i] - 1,b = (sumc - max(0, up[i+1] - 1) + P) % P;
					inc(ansc, 1ll * aa * b % P);
					inc(sumc, up[i] - 1);
					
					aa = up[i] - 1, b = (sumf - 1ll * max(0, up[i+1] - 1) * max(0, tf - 1) % P + P) % P;
					inc(ansf, 1ll * aa * b % P);
					inc(sumf, 1ll * aa * tf % P);
					++ tf;
				}
			}
		}
		
		printf("%lld %lld\n", 1ll * ansc * C % P , 1ll * ansf * F % P);
		
		clr();
	}
	return 0;
}
