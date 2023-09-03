#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
const int N=1010;
int T,id;
int n,m,c,f;
char ch[N][N];
int a[N][N];
ll cp[N][N],fp[N][N],nxt[N][N],dwn[N][N];
ll cans,fans;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;++i)
		{
			scanf("%s",ch[i]+1);
			for(int j=1;j<=m;++j)
			{
				a[i][j]=(ch[i][j]!='1');
			}
		}
		memset(cp,0,sizeof(cp));
		memset(fp,0,sizeof(fp));
		memset(nxt,0,sizeof(nxt));
		memset(dwn,0,sizeof(dwn));
		for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
		{
			if(a[i][j])
			{
				nxt[i][j]=nxt[i][j+1]+1;
				dwn[i][j]=dwn[i+1][j]+1;
			}
		}
		for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
		{
			if(a[i][j])
			{
				cp[i][j]=nxt[i][j]-1;
				fp[i][j]=(cp[i][j]*(dwn[i][j]-1))%mod;
				cp[i][j]=(cp[i][j]+cp[i+1][j])%mod;
				fp[i][j]=(fp[i][j]+fp[i+1][j])%mod;
			}
		}
		cans=fans=0;
		for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(a[i][j]&&a[i+1][j])
			{
				cans=(cans+(nxt[i][j]-1)*cp[i+2][j])%mod;
				fans=(fans+(nxt[i][j]-1)*fp[i+2][j])%mod;
			}
		}
		printf("%lld %lld\n",(cans*c)%mod,(fans*f)%mod);
	}
	return 0;
}







