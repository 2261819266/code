#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef unsigned long long ll;
const int MAXN = 100010;
const int B = 1199;
const int MAXB = 510;

int n, m, a[MAXN], b[MAXN], stka[MAXN], topa, stkb[MAXN], topb = 0, la[MAXN], ra[MAXN], lb[MAXN], rb[MAXN], pos[MAXN], lp[MAXB], rp[MAXB];

struct ques{
	int l, r, ind;
	bool operator<(const ques&o) const{return b[l]^b[o.l] ? b[l]<b[o.l] : r<o.r;}
}c[MAXN];
ll w[MAXN], wb[MAXN], tag[MAXN];

//inline void pd(int x)
//{
//	for(int i=lp[x];i<=rp[x];i++) w[i] += tag[x], wb[x] += tag[x];
//	tag[x] = 0;
//}
//inline void update(int l, int r, ull val)
//{
//	for(int i=l;i<=rp[pos[l]];i++) w[i] += val, wb[pos[i]] += val;
//	for(int i=pos[l]+1;i<pos[r];i++) tag[i] += val;
//	for(int i=lp[pos[r]];i<=r;i++) w[i] += val, wb[pos[i]] += val;
//}
//inline ll query(int l, int r, ull val)
//{
//	ll res = 0;
//	pd(pos[l]); pd(pos[r]);
//	for(int i=l;i<=rp[pos[l]];i++) res += w[i];
//	for(int i=pos[l]+1;i<pos[r];i++) res += tag[i]*(rp[i]-lp[i]+1);
//	for(int i=lp[pos[r]];i<=r;i++) res += w[i];
//	return res;
//}

struct sgt
{

struct node{
	int l, r;
	ll sum, tag, mx;
}t[MAXN<<2];
#define lc (k<<1)
#define rc (k<<1|1)
inline void pu(int k) { t[k].sum = t[lc].sum+t[rc].sum; t[k].mx = max(t[lc].mx, t[rc].mx); }
void build(int l, int r, int k = 1)
{
	t[k].l = l; t[k].r = r; t[k].sum = t[k].tag = t[k].mx = 0;
	if(l == r) return ;
	int mid = (l+r)>>1;
	build(l, mid, lc); build(mid+1, r, rc);
}
inline void upd(int k, ll v) {
	t[k].sum = v*(t[k].r-t[k].l+1);
	t[k].tag = t[k].mx = v;
}
inline void pd(int k)
{
	if(t[k].tag) upd(lc, t[k].tag), upd(rc, t[k].tag), t[k].tag = 0;
}
void update(int x, int y, ll v, int k = 1)
{
	if(t[k].l >=x && t[k].r <= y) return upd(k, v), void();
	pd(k);
	int mid = (t[k].l+t[k].r)>>1;
	if(x <= mid) update(x, y, v, lc);
	if(y > mid) update(x, y, v, rc);
	pu(k);
}
ll queryS(int x, int y, int k = 1)
{
	if(t[k].l >= x &&t[k].r <= y) return t[k].sum;
	pd(k);
	int mid = (t[k].l+t[k].r)>>1;
	ll res = 0;
	if(x <= mid) res += queryS(x, y, lc);
	if(y > mid) res += queryS(x, y, rc);
	return res;
}
ll queryM(int x, int y, int k = 1)
{
	if(t[k].l >= x &&t[k].r <= y) return t[k].mx;
	pd(k);
	int mid = (t[k].l+t[k].r)>>1;
	ll res = 0;
	if(x <= mid) res = max(res, queryM(x, y, lc));
	if(y > mid) res = max(res, queryM(x, y, rc));
	return res;
}
#undef lc
#undef rc
}Tal, Tar, Tbl, Tbr, tal, tar, tbl, tbr;

int I[MAXN], J[MAXN];
inline ll brute(int l, int r)
{
	ll res = 0;
	Tal.build(l, r); Tbl.build(l, r);
	for(int i=l;i<=r;i++) Tal.update(i, i, a[i]), Tbl.update(i, i, b[i]);
	for(int i=l;i<=r;i++) for(int j=i;j<=r;j++) res += Tal.queryM(i, j)*Tbl.queryM(i, j);
	Tal.build(l, r); Tbl.build(l, r);
	return res;
}

ll res = 0, ans[MAXN];
int nl, nr;

inline void updr(int x)
{
	int pa = la[x], pb = lb[x];
	ll sa = Tar.queryS(nl, pa-1), sb = Tbr.queryS(nl, pb-1);
	res += 1llu*a[x]*b[x]*(x-pa+1)*(x-pb+1) + sa*sb + sa*(x-pb+1)*b[x] + sb*(x-pa+1)*a[x];
	Tar.update(pa, x, a[x]); Tbr.update(pb, x, b[x]);
	Tal.update(x, x, max(1llu*a[x], Tal.queryM(nl, nr-1)));
	Tbl.update(x, x, max(1llu*b[x], Tbl.queryM(nl, nr-1)));
}
inline void updl(int x)
{
	int pa = ra[x], pb = rb[x];
	ll sa = Tal.queryS(pa+1, nr), sb = Tbl.queryS(pb+1, nr);
	res += 1llu*a[x]*b[x]*(pa-x+1)*(pb-x+1) + sa*sb + sa*(pb-x+1)*b[x] + sb*(pa-x+1)*a[x];
	Tal.update(pa, x, a[x]); Tbl.update(pb, x, b[x]);
	Tar.update(x, x, max(1llu*a[x], Tar.queryM(nl+1, nr)));
	Tbr.update(x, x, max(1llu*b[x], Tbr.queryM(nl+1, nr)));
}

inline void work()
{
	scanf("%*d%d",&n);
//	printf("%d\n",n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	for(int i=1;i<=n;i++)
	{
		while(topa && a[i] > a[stka[topa]]) ra[stka[topa--]] = i-1;
		la[i] = stka[topa]+1;
		stka[++topa] = i;
		while(topb && b[i] > b[stkb[topb]]) rb[stkb[topb--]] = i-1;
		lb[i] = stkb[topb]+1;
		stkb[++topb] = i;
		pos[i] = (i-1)/B+1;
	}
	for(int i=1;i<=pos[n];i++) lp[i] = rb[i-1]+1, rp[i] = lp[i]+B-1;
	for(int i=1;i<=topa;i++) ra[stka[i]] = n;
	for(int i=1;i<=topb;i++) rb[stkb[i]] = n;
	
//	for(int i=1;i<=n;i++) printf("%d %d\n",la[i],ra[i]);
//	puts("");
//	for(int i=1;i<=n;i++) printf("%d %d\n",lb[i],rb[i]);
//	puts("");
	
	scanf("%d",&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&c[i].l,&c[i].r), c[i].ind = i;
	sort(b+1, b+m+1);
	for(int i=1;i<=m;i++)
	{
		if(pos[c[i].l] != pos[c[i-1].l]) nl = rp[pos[c[i].l]], nr = nl-1, Tal.build(1, n), Tar.build(1, n), Tbl.build(1, n), Tbr.build(1, n);
		if(pos[c[i].l] == pos[c[i].r])
		{
			ans[c[i].ind] = brute(c[i].l, c[i].r);
			continue;
		}
		nl = rp[pos[c[i].l]];
		while(nr < c[i].r) updr(++nr);
		tal = Tal; tar = Tar; tbl = Tbl; tbr = Tbr;
		while(nl > c[i].l) updl(--nl);
		ans[c[i].ind] = res;
		Tal = tal; Tar = tar; Tbl = tbl; Tbr = tbl;
	}
	for(int i=1;i<=m;i++) printf("%llu\n",ans[i]);
}

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T = 1;
//	scanf("%d%*d",&T);
	while(T--) work();
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
