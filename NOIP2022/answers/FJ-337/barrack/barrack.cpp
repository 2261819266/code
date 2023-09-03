#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+5,mod=1e9+7;
int n,m,f[N],p2[N],s,fa[N],siz[N];
struct node{int u,v;}e[N];
inline int AD(LL x,int y){x+=y;return x>=mod?x-mod:x;}
inline int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}
int main()
{
	freopen("barrack.in","r",stdin);freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);bool ok=1;
	for(int i=1;i<=m;i++) scanf("%d%d",&e[i].u,&e[i].v),ok&=(e[i].u==i&&e[i].v==i+1);
	p2[0]=1;for(int i=1;i<=N-5;i++) p2[i]=2ll*p2[i-1]%mod;
	if(ok)
	{
		for(int i=1;i<=n;i++) f[i]=AD(s,1ll*p2[i-1]*(i-1)%mod),f[i]=AD(f[i],p2[i]-1),s=AD(s,AD(f[i],mod-p2[i-1]));
		printf("%d",f[n]);
	}
	else
	{
		int S;
		for(int i=0;i<(1<<m);i++)
		{
			for(int j=1;j<=n;j++) fa[j]=j,siz[j]=1;
			for(int j=1;j<=m;j++)
			{
				if(i&(1<<(j-1)))
				{
					int x=getf(e[j].u),y=getf(e[j].v);
					if(x!=y) fa[y]=x,siz[x]+=siz[y];
				}
			}S=0;
			for(int j=1;j<=n;j++) if(fa[j]==j) S=AD(S,p2[siz[j]]-1);
			s=AD(s,S);
		}
		printf("%d",s);
	}
	return 0;
}
/*
4 4
1 2
2 3
3 1
1 4
*/
