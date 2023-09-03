#include<cstdio>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cmath>
using namespace std;
typedef unsigned long long ULL;
const int N=7e5+10,P=20;
int st1[N][21],st2[N][21];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&st1[i][0]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&st2[i][0]);
	}
	int lp=log2(n);
	for(int j=1;j<=lp;j++)
	{
		for(int i=1;i<=n;i++)
		{
			int t=i+(1<<(j-1));
			st1[i][j]=max(st1[i][j-1],st1[t][j-1]);
			st2[i][j]=max(st2[i][j-1],st2[t][j-1]);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		ULL ans=0;
		for(int j=l;j<=r;j++)
		{
			for(int k=j;k<=r;k++)
			{
				int t=log2(k-j+1);
				int g=k-(1<<t)+1;
				int p1=max(st1[j][t],st1[g][t]);
				int p2=max(st2[j][t],st2[g][t]);
				ans=ans+(ULL)p1*p2;
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
