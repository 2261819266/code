#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
typedef unsigned long long ll;
ll b1[3005][3005]={0};
ll b2[3005][3005]={0};
ll f[3005]={0},s[3005]={0};
ll n,t,m,l,r,mx=1,ans=0,pf=0;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=63;i++)mx*=2;
	mx-=1;
	mx*=2;
	mx+=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				b1[i][j]=b1[j][i]=f[j];
				b2[i][j]=b2[j][i]=s[j];
				continue;
			}
			b1[i][j]=b1[j][i]=max(f[j],b1[i][j-1]);
			b2[i][j]=b2[j][i]=max(s[j],b2[i][j-1]);
		}
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
		{
			for(int p=j;p<=r;p++)
			{
				ans=b1[j][p]*b2[j][p];
				if(mx-pf>=ans)pf+=ans;
				else 
				{
					ans-=mx-pf+1;
					pf+=ans;
				
			}cout<<pf<<" "<<ans<<endl;
		}
		}
		
	}
	printf("%lld",pf);
	return 0;
} 
/*

*/
