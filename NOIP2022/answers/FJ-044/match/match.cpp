#include<cstdio>
#include<iostream>
#define re register
using namespace std;
const int N=250005;
int T,n,Q;
int a[N],b[N];
int f[N][31],g[N][31];
int lg[N]={-1};
inline void prework()
{
	for(re int i=1;i<=n;i++)
	{
		f[i][0]=a[i];
		g[i][0]=b[i];
	}
	for(re int j=1;j<=lg[n];j++)
	{
		for(re int i=1;i+(1<<j)-1<=n;i++)
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
			g[i][j]=max(g[i][j-1],g[i+(1<<(j-1))][j-1]);
		}
	}
}
inline int query1(int l,int r)
{
	int k=lg[r-l+1];
	return max(f[l][k],f[r-(1<<k)+1][k]);
}
inline int query2(int l,int r)
{
	int k=lg[r-l+1];
	return max(g[l][k],g[r-(1<<k)+1][k]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(re int i=1;i<=n;i++) lg[i]=lg[i>>1]+1;
	for(re int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(re int i=1;i<=n;i++) scanf("%d",&b[i]);
	scanf("%d",&Q);
	prework();
	while(Q--)
	{
		int l,r;
		long long ans=0;
		scanf("%d%d",&l,&r);
		for(re int i=l;i<=r;i++)
		{
			for(re int j=i;j<=r;j++)
			{
				int ans1=query1(i,j);
				int ans2=query2(i,j);
				ans+=ans1*ans2;
			}
		}
		printf("%lld\n",ans);
	}
			
	return 0;
}
