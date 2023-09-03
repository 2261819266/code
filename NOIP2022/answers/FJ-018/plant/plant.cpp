#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1010;
const ll mo=998244353;
int T,id,n,m;
bool g[N][N];
ll p[N][N],q[N][N],pq[N][N],f[N][N],C,F;
void work()
{
	char ch; ll ansc=0,ansf=0;
	scanf("%d%d%lld%lld\n",&n,&m,&C,&F);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			ch=getchar();
			g[i][j]=ch^48;
		}
		ch=getchar();
	}
	ll k,t;
	for(int i=1;i<=n;i++)
	{
		k=0,t=0;
		for(int j=m;j>=1;j--)
			if(g[i][j]){p[i][j]=0;t=k;}
			else{p[i][j]=k-t;k++;}
	}
	for(int j=1;j<=m;j++)
		for(int i=3;i<=n;i++)
			if(g[i][j])
			{
				while((g[i][j]||g[i-1][j]||g[i-2][j])&&i<=n) i++;
				i--;
			}
			else
			{
				if(g[i-2][j]||g[i-1][j]) continue;
				q[i][j]=p[i-2][j]+q[i-1][j];
			}
	for(int j=1;j<=m;j++)
	{
		k=0,t=0;
		for(int i=n;i>=1;i--)
			if(g[i][j]){f[i][j]=0;t=k;}
			else{f[i][j]=k-t;k++;}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			pq[i][j]=p[i][j]*q[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ansc=(ansc+pq[i][j])%mo,ansf=(ansf+pq[i][j]*f[i][j])%mo;
	printf("%lld %lld\n",C*ansc,F*ansf);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) q[i][j]=0;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--) work();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
