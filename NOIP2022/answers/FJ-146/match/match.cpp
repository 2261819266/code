#include<cstdio>
#include<vector>
const int N=250007;
typedef unsigned long long ull;
struct data{ull val;int t;};
data chg(int x)
{
	int k=__builtin_ffs(x)-1;
	return {(ull)(x>>k),k};
}
ull gval(data z){return (z.t>=64)?0:(z.val<<z.t);}
data inv(data z)
{
	ull x=z.val,r=1;
	for(int i=63;i;--i)r*=x,x*=x;
	return {r,-z.t};
}
data operator*(data a,data b){return {a.val*b.val,a.t+b.t};}
data operator+(data a,data b)
{
	if(!a.val||a.t-b.t>=64)return b;
	if(!b.val||b.t-a.t>=64)return a;
	data res;
	if(a.t<b.t)res={a.val+(b.val<<(b.t-a.t)),a.t};
	else res={b.val+(a.val<<(a.t-b.t)),b.t};
	if(!res.val)return {0,0};
	if(!(res.val&1))
	{
		int k=__builtin_ffsll((long long)(res.val>>1));
		return {res.val>>k,res.t+k};
	}
	return res;
}
void operator+=(data&a,data b){a=a+b;}
data sum[N*4],hsum[N*4],ad[N*4],ml[N*4];
int a[N],b[N],astk[N],atp,bstk[N],btp;
struct pii{int l,id;};
std::vector<pii> qr[N];
void tadd(int x,data v){hsum[x]+=sum[x]*v;ad[x]+=ml[x]*v;}
void tmul(int x,data v){sum[x]=sum[x]*v;ml[x]=ml[x]*v;}
void push(int x)
{
	if(ad[x].val)tadd(x<<1,ad[x]),tadd(x<<1|1,ad[x]),ad[x]={0,0};
	if(ml[x].t||ml[x].val!=1)tmul(x<<1,ml[x]),tmul(x<<1|1,ml[x]),ml[x]={1,0};
}
void pull(int x)
{
	sum[x]=sum[x<<1]+sum[x<<1|1];
	hsum[x]=hsum[x<<1]+hsum[x<<1|1];
}
void build(int l,int r,int rt)
{
	ml[rt]={1,0};
	if(l==r){sum[rt]=chg(a[l])*chg(b[l]);return;}
	int mid=(l+r)>>1;
	build(l,mid,rt<<1);
	build(mid+1,r,rt<<1|1);
	pull(rt);
}
void upd(int L,int R,data k,int l,int r,int rt)
{
	if(L>R)return;
	if(L<=l&&r<=R)return tmul(rt,k);
	int mid=(l+r)>>1;push(rt);
	if(L<=mid)upd(L,R,k,l,mid,rt<<1);
	if(R>mid)upd(L,R,k,mid+1,r,rt<<1|1);
	pull(rt);
}
void spr(int p,int l,int r,int rt)
{
	if(p>=r)return tadd(rt,{1,0});
	int mid=(l+r)>>1;push(rt);
	spr(p,l,mid,rt<<1);
	if(p>mid)spr(p,mid+1,r,rt<<1|1);
	pull(rt);
}
data qry(int p,int l,int r,int rt)
{
	if(p<=l)return hsum[rt];
	int mid=(l+r)>>1;push(rt);
	data ans=qry(p,mid+1,r,rt<<1|1);
	if(p<=mid)ans+=qry(p,l,mid,rt<<1);
	return ans;
}
ull ans[N];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int n,q,x,y;scanf("%*d%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	build(1,n,1);scanf("%d",&q);
	for(int i=1;i<=q;++i)scanf("%d%d",&x,&y),qr[y].push_back({x,i});
	for(int i=1;i<=n;++i)
	{
		while(atp&&a[astk[atp]]<=a[i])upd(astk[atp-1]+1,astk[atp],inv(chg(a[astk[atp]]))*chg(a[i]),1,n,1),--atp;
		while(btp&&b[bstk[btp]]<=b[i])upd(bstk[btp-1]+1,bstk[btp],inv(chg(b[bstk[btp]]))*chg(b[i]),1,n,1),--btp;
		astk[++atp]=i;bstk[++btp]=i;
		spr(i,1,n,1);
		for(pii z:qr[i])ans[z.id]=gval(qry(z.l,1,n,1));
	}
	for(int i=1;i<=q;++i)
		printf("%lld\n",ans[i]);
	return 0;
}
