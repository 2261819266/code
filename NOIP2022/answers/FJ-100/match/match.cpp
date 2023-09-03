#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll read()
{
	char c=getchar(); ll res=0, f=1;
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) {res=(res<<3)+(res<<1)+(c^48); c=getchar();}
	return res*f;
}
void write(unsigned ll x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=2e5+1;
int id,n,q,a[N],b[N];

struct segtree {int maxa,maxb;} t[N<<2];
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((l+r)>>1)
void pushup(int pos) {t[pos].maxa = max(t[ls].maxa, t[rs].maxa); t[pos].maxb = max(t[ls].maxb, t[rs].maxb);}
void build(int pos,int l,int r)
{
	if(l==r) {t[pos]=(segtree){a[l],b[l]}; return;}
	build(ls,l,mid); build(rs,mid+1,r);
	pushup(pos);
}
segtree ask(int pos,int ql,int qr,int l,int r)
{
	if(ql<=l && r<=qr) return t[pos];
	if(ql<=mid) return ask(ls,ql,qr,l,mid);
	else if(qr>mid) return ask(rs,ql,qr,mid+1,r);
	else
	{
		segtree r1=ask(ls,ql,qr,l,mid), r2=ask(rs,ql,qr,mid+1,r);
		return (segtree){max(r1.maxa, r2.maxa), max(r1.maxb, r2.maxb)};
	}
}
#undef l
#undef r
#undef mid

int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	id=read(), n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	build(1,1,n);
	q=read();
	for(int i=1,l,r;i<=q;++i)
	{
		l=read(), r=read();
		unsigned ll ans=0;
		for(int p=l;p<=r;++p)
		for(int q=p;q<=r;++q)
		{
			segtree res=ask(1,p,q,1,n);
			ans += 1ull*res.maxa*res.maxb;
		}
		write(ans); putchar('\n');
	}
}
/*
0 2
2 1
1 2
1
1 2*/
