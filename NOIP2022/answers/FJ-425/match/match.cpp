#include<bits/stdc++.h>
using namespace std;

const int N = 250010;
const unsigned long long P = (1 << 31);
typedef long long LL;

struct tree{
	int l, r;
	LL maxn;
}tr1[N << 2], tr2[N << 2];
int T, n, a[N], b[N], Q;

void pushup(tree &u, tree &l, tree &r){
	u.maxn = max(l.maxn, r.maxn);
}

void pushup1(int u){
	pushup(tr1[u], tr1[u << 1], tr1[u << 1 | 1]);
}
void pushup2(int u){
	pushup(tr2[u], tr2[u << 1], tr2[u << 1 | 1]);
}

void build(int u,int l, int r){
	tr1[u] = {l, r, 0};
	tr2[u] = {l, r, 0};
	if(l == r){
		tr1[u].maxn = a[l];
		tr2[u].maxn = b[l];
		return ;
	}
	int mid = l + r >> 1;
	build (u << 1, l ,mid);
	build(u << 1 | 1, mid + 1, r);
	pushup1(u);
	pushup2(u);
}

LL q1(int u, int l, int r){
	if(tr1[u].l >= l && tr1[u].r <= r){
		return tr1[u].maxn;
	}
	int mid = tr1[u].l + tr1[u].r >> 1;
	LL maxn = -1;
	if(l <= mid) maxn = q1(u << 1, l, r); 
	if(r > mid) maxn = max(maxn, q1(u << 1 | 1, l, r));
	return maxn;
}
LL q2(int u, int l, int r){
	if(tr2[u].l >= l && tr2[u].r <= r)
		return tr2[u].maxn;
	int mid = tr2[u].l + tr2[u].r >> 1;
	LL maxn = -1;
	if(l <= mid) maxn = q2(u << 1, l ,r);
	if(r > mid) maxn = max(q2(u << 1 | 1, l ,r), maxn);
	return maxn;
}


int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	cin >> T >> n;
	for(int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i ++)
		scanf("%d", &b[i]);
	build(1, 1, n);
	cin >> Q;
	while(Q--){
		int l, r;
		LL ans = 0;
		scanf("%d%d", &l, &r);
//		cout << l << " " << r << endl;
		for(int p = l; p <= r; p ++){
			for(int q = p; q <= r ; q ++)
			{
//				cout << p << " " << q <<  endl;
				ans = (ans % P + (q1(1, p, q) % P * q2(1, p, q) % P) % P) % P;
			}
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}