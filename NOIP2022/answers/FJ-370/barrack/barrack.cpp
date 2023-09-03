#include <bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,MAXM=1e6+10,mod=1e9+7;
int n,m;
int U[MAXM],V[MAXM];
struct node
{
	int to,nxt;
} edg[MAXM<<1];
int cnt,hea[MAXN];
void add(int u,int v)
{
	cnt++;
	edg[cnt].to=v;
	edg[cnt].nxt=hea[u];
	hea[u]=cnt;
}
int fa[MAXN];
int getfa(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=getfa(fa[x]);
}
void merge(int x,int y)
{
	int fx=getfa(x),fy=getfa(y);
	if(fx==fy) return;
	fa[fx]=fy;
}
int ksm(int u,int v)
{
	int res=1;
	while(v)
	{
		if(v&1) res=1ll*res*u%mod;
		u=1ll*u*u%mod; v>>=1;
	}
	return res;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&U[i],&V[i]);
		add(U[i],V[i]); add(U[i],V[i]);
	}
	if(n<=16&&m<=25)
	{
		long long ans=0;
		for(int i=1;i<(1<<n);i++)
			for(int j=0;j<(1<<m);j++)
			{
				int flaa=0;
				for(int k=0;k<m;k++)
					if(!(j&(1<<k)))
					{
						for(int id=1;id<=n;id++) fa[id]=id;
						for(int e=0;e<m;e++)
							if(e!=k)
								merge(U[e],V[e]);
						int fla=0,f=0;
						for(int id=0;id<n;id++)
							if(i&(1<<id))
							{
								if(fla==0) fla=getfa(id+1);
								else if(getfa(id+1)!=fla) { f=1; break;}
							}
						if(f) { flaa=1; break;}
					}
				if(!flaa) ans++;
			}
		printf("%d",ans%mod);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
