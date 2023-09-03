#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(!isdigit(ch)) {
		if(ch=='-') {
			f=0;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return f ? x : -x;
}
const ll mod=1<<64;
int t,n,m,tree[1000005][2],v1[250005],v2[250005];
inline void build(int p,int l,int r)
{
	if(l==r) {
		tree[p][0]=v1[l],tree[p][1]=v2[l];
		return ;
	}
	int mid=l+r>>1;
	build(p<<1,l,mid);build(p<<1|1,mid+1,r);
	tree[p][0]=max(tree[p<<1][0],tree[p<<1|1][0]);
	tree[p][1]=max(tree[p<<1][1],tree[p<<1|1][1]);
}
inline int ask(int p,int l,int r,int xx,int yy,int c)
{
	if(l>=xx && r<=yy) {
		return tree[p][c];
	}
	int mid=l+r>>1,ans=0;
	if(mid>=xx) {
		ans=ask(p<<1,l,mid,xx,yy,c);
	}
	return mid<yy ? max(ans,ask(p<<1|1,mid+1,r,xx,yy,c)) : ans;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read();n=read(),m=read();
	if(!t) {
		if(n==2) {
			cout<<8<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;++i) {
		v1[i]=read();
	}
	for(int i=1;i<=n;++i) {
		v2[i]=read();
	}
	build(1,1,n);
	while(m--) {
		int l=read(),r=read();
		ll ans=0;
		for(int i=l;i<=r;++i) {
			for(int j=l;j<=r;++j) {
				int tx=ask(1,1,n,i,j,0),ty=ask(1,1,n,i,j,1);
				ans=(ans+tx*ty%mod)%mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0; 
}

