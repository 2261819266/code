#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define eb emplace_back
#define ls u<<1
#define rs u<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef __int128 LL;
typedef unsigned long long ull;
int n,m,x,y,a[250005],b[250005],stk1[250005],top1,stk2[250005],top2,Res[3];
vector<pii> vec[250005];
LL X,Y,X1,Y1,Ans,Prd,Prd2;
__uint128_t U;
ull ans[250005];
struct seg{
	int p,inv[250005],sum[1000005],tag[1000005],sum2[1000005],tag2[1000005];
	inline int add(int x,int y){return (x+=y)>=p?x-p:x;}
	inline void inc(int &x,int y){(x+=y)>=p?x-=p:0;}
	inline void pushup(int u){
		sum[u]=add(sum[ls],sum[rs]);
		sum2[u]=add(sum2[ls],sum2[rs]);
	}
	void build(int u,int l,int r){
		tag[u]=1;
		if(l==r)return sum[u]=1,void();
		int mid=(l+r)>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
		pushup(u);
	}
	inline void init(int P){
		p=P,inv[1]=1;
		for(int i=2;i<=n;++i)
			inv[i]=(ll)(p-p/i)*inv[p%i]%p;
		build(1,1,n);
	}
	inline void calc(int u,int z,int w){
		sum2[u]=(sum2[u]+(ll)sum[u]*w)%p;
		sum[u]=(ll)sum[u]*z%p;
		tag2[u]=(tag2[u]+(ll)tag[u]*w)%p;
		tag[u]=(ll)tag[u]*z%p;
	}
	inline void pushdown(int u){
		if(tag[u]!=1 || tag2[u]){
			calc(ls,tag[u],tag2[u]);
			calc(rs,tag[u],tag2[u]);
			tag[u]=1,tag2[u]=0;
		}
	}
	void modi(int u,int l,int r,int x,int y,int z){
		if(x<=l && r<=y)return calc(u,z,0);
		pushdown(u);
		int mid=(l+r)>>1;
		if(x<=mid)modi(ls,l,mid,x,y,z);
		if(y>mid)modi(rs,mid+1,r,x,y,z);
		pushup(u);
	}
	void chg(int u,int l,int r,int x,int y){
		if(x<=l && r<=y){
			inc(sum2[u],sum[u]);
			inc(tag2[u],tag[u]);
			return;
		}
		pushdown(u);
		int mid=(l+r)>>1;
		if(x<=mid)chg(ls,l,mid,x,y);
		if(y>mid)chg(rs,mid+1,r,x,y);
		pushup(u);
	}
	int que(int u,int l,int r,int x,int y){
		if(x<=l && r<=y)return sum2[u];
		pushdown(u);
		int mid=(l+r)>>1,res=0;
		if(x<=mid)inc(res,que(ls,l,mid,x,y));
		if(y>mid)inc(res,que(rs,mid+1,r,x,y));
		return res;
	}
	inline void Modi(int l,int r,int x,int y){
		modi(1,1,n,l,r,(ll)y*inv[x]%p);
	}
}tr[3];
inline void Modify(int l,int r,int x,int y){
	for(int i=0;i<3;++i)tr[i].Modi(l,r,x,y);
}
void exgcd(LL a,LL b){
	if(!b)return X=1,Y=0,void();
	exgcd(b,a%b);
	LL t=X;
	X=Y,Y=t-a/b*Y;
}
inline LL mul(LL x,LL y,LL p){
	if(x<0)x+=p;
	if(y<0)y+=p;
	LL res=0;
	while(x){
		if(x&1)(res+=y)>=p?res-=p:0;
		x>>=1;
		(y+=y)>=p?y-=p:0;
	}
	return res;
}
inline ull Clc(int l,int r){
	for(int i=0;i<3;++i)
		Res[i]=tr[i].que(1,1,n,l,r);
	Ans=Res[0]+mul(mul(X,Res[1]-Res[0],Prd2),1000000007,Prd2);
	if(Ans>=Prd2)Ans-=Prd2;
	Ans=Ans+mul(mul(X1,Res[2]-Ans,Prd),Prd2,Prd);
	if(Ans>=Prd)Ans-=Prd;
	if(Ans<0)Ans+=Prd;
	return (ull)(Ans&U);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%*d%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		vec[y].eb(pii(x,i));
	}
	tr[0].init(1000000007);
	tr[1].init(1000000009);
	tr[2].init(998244353);
	Prd2=(LL)1000000007*1000000009;
	Prd=Prd2*998244353;
	exgcd(Prd2,998244353);
	X1=X,Y1=Y;
	exgcd(1000000007,1000000009);
	for(int i=0;i<64;++i)U=(U<<1)|1;
	for(int i=1;i<=n;++i){
		while(top1 && a[i]>a[stk1[top1]]){
			Modify(stk1[top1-1]+1,stk1[top1],a[stk1[top1]],a[i]);
			--top1;
		}
		Modify(i,i,1,a[i]);
		stk1[++top1]=i;
		while(top2 && b[i]>b[stk2[top2]]){
			Modify(stk2[top2-1]+1,stk2[top2],b[stk2[top2]],b[i]);
			--top2;
		}
		Modify(i,i,1,b[i]);
		stk2[++top2]=i;
		for(int j=0;j<3;++j)
			tr[j].chg(1,1,n,1,i);
		for(auto t:vec[i])ans[t.se]=Clc(t.fi,i);
	}
	for(int i=1;i<=m;++i)
		printf("%llu\n",ans[i]);
	return 0;
}
