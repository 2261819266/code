//Checkmate, I couldn't lose.
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define pii pair<int,int>
#define mp make_pair

inline int read() {
	int x = 0;int f = 1;char c = getchar();
	while (!isdigit(c)) {if (c == '-') {f = -1;}c = getchar();}
	while (isdigit(c)) {x = x * 10 + c - 48;c = getchar();}
	return x * f;
}
const int N = 3e5 + 10;
int n,q,T;
ull a[N],b[N];

struct segt {
	
	ull a[N];

	struct node {
		int l,r;
		ull maxx;
	}tree[N<<2];

	void pushup(int p) {
		tree[p].maxx = max(tree[p << 1].maxx,tree[p << 1 | 1].maxx);
	}
	
	void build(int p,int l,int r) {
		tree[p].l = l,tree[p].r =r;
		if (l == r) {
			tree[p].maxx = a[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(p << 1,l,mid);
		build(p << 1 | 1,mid + 1,r);
		pushup(p);
	}
	
	ull query(int p,int l,int r) {
		if (tree[p].l >= l && tree[p].r <= r) {
			return tree[p].maxx;
		}
		ull ans = 0;
		int mid = (tree[p].l + tree[p].r) >> 1;
		if (l <= mid) ans = max(ans,query(p << 1,l,r));
		if (r > mid) ans = max(ans,query(p << 1 | 1,l,r));
		return ans;
	}
}t1,t2;

ull pre[3010][3010];

ull calc(int x,int y) {
	//printf("%llu %llu %llu %llu\n",pre[y][y] ,pre[x-1][y] , pre[x][y-1] ,pre[x-1][y-1]);
	return pre[y][y] - pre[x-1][y] - pre[y][x-1] + pre[x-1][x-1];
}

signed main() {
	FO(match)
	T = read();n = read();
	for (int i = 1;i <= n;++i) {
		a[i] = read();t1.a[i] = a[i];
	}
	for (int i = 1;i <= n;++i) {
		b[i] = read();t2.a[i] = b[i];
	}
	t1.build(1,1,n);t2.build(1,1,n);
	if (n <= 3000) {
		for (int l = 1;l <= n;++l) {
			for (int r = l;r <= n;++r) {
				pre[l][r] = t1.query(1,l,r) * t2.query(1,l,r);
			}
		}
		for (int l = 1;l <= n;++l) {
			for (int r = 1;r <= n;++r) {
				pre[l][r] += pre[l-1][r]+pre[l][r-1]-pre[l-1][r-1];
			}
		}
		q = read();
		while (q--) {
			int l,r;l = read();r = read();
			printf("%llu\n",calc(l,r));
		}
	} else {
		q = read();
		while (q--) {
			int l,r;l = read();r = read();
			ull ans = 0;
			for (int p = l;p <= r;++p) {
				for (int q = p;q <= r;++q) {
					ans += t1.query(1,p,q) * t2.query(1,p,q);
				}
			}
			printf("%llu\n",ans);
		}
	}
	/*for (int i = 1;i <= n;++i) {
		for (int j = 1;j <= n;++j) {
			if (pre[i][j]) printf("%llu ",pre[i][j]);
			else printf("0 ");
		}
		puts("");
	}*/
	return 0;
}
