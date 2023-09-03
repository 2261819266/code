#include <cstdio>
#include <cctype>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int,int> pii;
template<typename T1,typename T2> void cmin(T1 &a,const T2 &b){if(a>b)a=b;}
template<typename T1,typename T2> void cmax(T1 &a,const T2 &b){if(a<b)a=b;}

const int N=250005;
int T,n,a[N],b[N],Q,stk[N],tot,pre[N],nxt[N];

//struct SegT{
//	int l,r;
//	llu s0,s1,add0,add1;
//	void padd0(llu x){
//		s0+=(r-l+1)*x;
//		add0+=x;
//	}
//	void padd1(llu x){
//		s1+=(r-l+1)*x;
//		add1+=x;
//	}
//}t[N<<2];
//#define mid ((t[p].l+t[p].r)>>1)
//#define lc(p) (p<<1)
//#define rc(p) ((p<<1)|1)
//void Pushup(int p){
//	t[p].s0=t[lc(p)].s0+t[rc(p)].s0;
//	t[p].s1=t[lc(p)].s1+t[rc(p)].s1;
//}
//void Pushdown(int p){
//	if(t[p].add0){
//		t[lc(p)].padd0(t[p].add0);
//		t[rc(p)].padd0(t[p].add0);
//		t[p].add0=0;
//	}
//	if(t[p].add1){
//		t[lc(p)].padd1(t[p].add1);
//		t[rc(p)].padd1(t[p].add1);
//		t[p].add1=0;
//	}
//}
//void Build(int p,int l,int r){
//	t[p].l=l,t[p].r=r;
//	t[p].s0=t[p].s1=0u;
//	t[p].add0=t[p].add1=0u;
//	if(l==r)
//		return;
//	Build(lc(p),l,(l+r)>>1);
//	Build(rc(p),((l+r)>>1)+1,r);
//}
//void Add(int p,int i,int l,int r,llu v){
//	if(l<=t[p].l && t[p].r<=r){
//		t[p].padd0(v);
//		t[p].padd1(v*(i-1));
//		return;
//	}
//	Pushdown(p);
//	if(l<=mid)
//		Add(lc(p),i,l,r,v);
//	if(mid<r)
//		Add(rc(p),i,l,r,v);
//	Pushup(p);
//}
//llu Ask(int p,int i,int l,int r){
//	if(l<=t[p].l && t[p].r<=r)
//		return t[p].s0*i-t[p].s1;
//	Pushdown(p);
//	llu s=0;
//	if(l<=mid)
//		s+=Ask(lc(p),i,l,r);
//	if(mid<r)
//		s+=Ask(rc(p),i,l,r);
//	return s;
//}
//#undef mid
//#undef lc
//#undef rc

struct T{
	int n;
	llu c1[N],c2[N];
	void clr(int n_){
		n=n_;
		fill_n(c1+1,n,0u);
		fill_n(c2+1,n,0u);
	}
	void add_(llu *c,int p,llu v){
		for(int i=p;i<=n;i+=i&-i)
			c[i]+=v;
	}
	llu qry_(llu *c,int p){
		llu s=0;
		for(int i=p;i;i&=i-1)
			s+=c[i];
		return s;
	}
	void add(int l,int r,llu v){
		add_(c1,l,v);
		add_(c1,r+1,-v);
		add_(c2,l,l*v);
		add_(c2,r+1,-(r+1)*v);
	}
	llu qry(int p){return (p+1)*qry_(c1,p)-qry_(c2,p);}
	llu qry(int l,int r){return qry(r)-qry(l-1);}
}t0,t1;

llu Query(int l,int r){
	auto Build=[&](int _,int l,int r){
		t0.clr(r-l+1);
		t1.clr(r-l+1);
	};
	auto Add=[&](int _,int i,int a,int b,llu v){
		a=a-l+1,b=b-l+1;
		t0.add(a,b,v);
		t1.add(a,b,v*(i-1));
	};
	auto Ask=[&](int _,int i,int a,int b){
		a=a-l+1,b=b-l+1;
		return t0.qry(a,b)*i-t1.qry(a,b);
	};
	tot=0;
	stk[tot++]=l-1;
	for(int i=l;i<=r;++i){
		while(tot>1 && pii(b[stk[tot-1]],stk[tot-1])<pii(b[i],i))
			--tot;
		pre[i]=stk[tot-1]+1;
		stk[tot++]=i;
	}
	tot=0;
	stk[tot++]=r+1;
	for(int i=r;i>=l;--i){
		while(tot>1 && pii(b[stk[tot-1]],stk[tot-1])<pii(b[i],i))
			--tot;
		nxt[i]=stk[tot-1]-1;
		stk[tot++]=i;
	}
	vector<array<int,4>> e,q;
	e.reserve((r-l+1)*2);
	for(int i=l;i<=r;++i){
		e.push_back({pre[i],i,nxt[i],b[i]});
		e.push_back({i+1,i,nxt[i],-b[i]});
	}
	sort(e.begin(),e.end());
	tot=0;
	stk[tot++]=l-1;
	for(int i=l;i<=r;++i){
		while(tot>1 && pii(a[stk[tot-1]],stk[tot-1])<pii(a[i],i))
			--tot;
		pre[i]=stk[tot-1]+1;
		stk[tot++]=i;
	}
	tot=0;
	stk[tot++]=r+1;
	for(int i=r;i>=l;--i){
		while(tot>1 && pii(a[stk[tot-1]],stk[tot-1])<pii(a[i],i))
			--tot;
		nxt[i]=stk[tot-1]-1;
		stk[tot++]=i;
	}
	q.reserve((r-l+1)*2);
	for(int i=l;i<=r;++i){
		if(pre[i]>l)
			q.push_back({pre[i]-1,i,nxt[i],-a[i]});
		q.push_back({i,i,nxt[i],a[i]});
	}
	sort(q.begin(),q.end());
	Build(1,l,r);
	llu ans=0;
	for(int p=l,i=0,j=0;p<=r+1;++p){
		for(;i<int(e.size()) && e[i][0]==p;++i)
			Add(1,p,e[i][1],e[i][2],e[i][3]);
		for(;j<int(q.size()) && q[j][0]==p;++j)
			ans+=Ask(1,p,q[j][1],q[j][2])*q[j][3];
	}
	return ans;
}

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
		scanf("%d",b+i);
	scanf("%d",&Q);
	for(int l,r;Q--;){
		scanf("%d%d",&l,&r);
		printf("%llu\n",Query(l,r));
	}
	return 0;
}
