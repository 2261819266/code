#include <bits/stdc++.h>
#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid ((l+r)>>1)
using namespace std;
typedef unsigned long long ll;
typedef long long l2;
const l2 N=300005;
ll lm=18446744073709551615;
l2 seq[2][N];
l2 tr1[N*4], tr2[N*4];
void push_up(l2 p, l2 tr[]){
	tr[p] = max(tr[ls], tr[rs]);
}
ll mp(ll a, ll b){
	ll tlm=lm-a;
	if (b > tlm){
		return b-tlm;
	}
	return a+b;
}
void build(l2 p, l2 l, l2 r, l2 tr[], l2 sqn){
	if (l == r){
		tr[p] = seq[sqn][l];
		return;
	}
	build(ls, l, mid, tr, sqn);
	build(rs, mid+1, r, tr, sqn);
	push_up(p, tr);
}
l2 query(l2 p, l2 nl, l2 nr, l2 l, l2 r, l2 tr[]){
	if (nl <= l and nr >= r){
		return tr[p];
	}
	long long res=-10000000000000;
	if (nl <= mid)res = max(res, query(ls, nl, nr, l, mid, tr));
	if (nr > mid)res = max(res, query(rs, nl, nr, mid+1, r, tr));
	return res;
}
int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	l2 n, id, ta, tb;
	scanf("%lld %lld", &id, &n);
	for (l2 x=1;x<=n;++x){
		scanf("%lld", &seq[0][x]);
	}
	for (l2 x=1;x<=n;++x){
		scanf("%lld", &seq[1][x]);
	}
	build(1, 1, n, tr1, 0);
	build(1, 1, n, tr2, 1);
	l2 t;
	scanf("%lld", &t);
	while (t--){
		ll ans=0;
		scanf("%lld %lld", &ta, &tb);
		for (ll x=ta;x<=tb;++x){
			for (ll y=x;y<=tb;++y){
				ll ma=query(1, x, y, 1, n, tr1), mb=query(1, x, y, 1, n, tr2);
				ans = mp(ma*mb, ans);
			}
		}
		printf("%lld\n", ans);
	}
}
