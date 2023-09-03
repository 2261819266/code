#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int t,id,n,m;
long long ans1,ans2,c,f,od=998244353,h[1005][1005];
char a[1005][1005];
int main ()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
		for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) h[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=1;j--) 
				if(a[i][j]=='0') h[i][j]=h[i][j+1]+1; 
				else h[i][j]=0;			
		}
		ans1=ans2=0;
		for(int j=1;j<=m;j++)
		{
			long long s=0;
			for(int i=n;i>=1;i--)
			{
				long long x=(h[i][j]>1?h[i][j]-1:0);
				ans1=(ans1+s*x)%od;
				if(h[i][j]==0) s=0;
				else s+=(h[i+1][j]>1?h[i+1][j]-1:0);
			}	
		}
		for(int j=1;j<=m;j++)
		{
			long long s1=0,s2=0;
			for(int i=n;i>=1;i--)
			{
				long long x=(h[i][j]>1?h[i][j]-1:0);
				ans2=(ans2+s2*x%od)%od;
				if(h[i][j]==0) s1=s2=0;
				else s2=(s2+(h[i+1][j]>1&&s1>1?(h[i+1][j]-1)*(s1-1):0))%od,s1++;
			}	
		}	
		printf("%lld %lld\n",ans1*c%od,ans2*f%od);
	}
}
