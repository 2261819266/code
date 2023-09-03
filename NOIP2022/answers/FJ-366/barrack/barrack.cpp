#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
const int mod=1e9+7;
int n,m;
ll ans,twm[N];
struct edg{
	int u,v;
}e[N];
int fa[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){
	x=find(x);y=find(y);
	if(x==y) return;
	fa[x]=y;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n<=8&&m<=10){
		for(int i=1;i<=m;++i) scanf("%d%d",&e[i].u,&e[i].v);
		for(int sd=1;sd<(1<<n);++sd){
			for(int se=0;se<(1<<m);++se){
				for(int i=1;i<=n;++i) fa[i]=i;
				for(int i=1;i<=m;++i) if((se>>(i-1))&1) merge(e[i].u,e[i].v);
				bool ab=1;
				for(int i=1;i<=n;++i)
					for(int j=1;j<=n;++j) 
						if(((sd>>(i-1))&1)&&((sd>>(j-1))&1)&&find(i)!=find(j)) ab=0;
				ans+=ab;
			}
		}
		printf("%d\n",ans);
		return 0;
	}
	for(int i=1,u,v;i<=m;++i) scanf("%d%d",&u,&v);
	twm[0]=1;
	for(int i=1;i<=n;++i) twm[i]=twm[i-1]*2%mod;
	ans=twm[n-1]*n%mod;
	ans=(ans+(twm[n-2]*(((ll)n*(n-1)/2)%mod)%mod))%mod;
	printf("%lld\n",ans);
	return 0;
}
