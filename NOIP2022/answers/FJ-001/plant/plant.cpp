#include<bits/stdc++.h>
using namespace std;
bool mp[1005][1005];
long long a[1005][1005];
long long b[1005][1005];		
char c[1005][1005];
long long T,id,n,m,e,f,ans1,ans2;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&T,&id);
	while(T--)
	{
		ans1=0,ans2=0;
		scanf("%lld%lld%lld%lld",&n,&m,&e,&f);
		memset(c,0,sizeof(c));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(mp,0,sizeof(mp));
		for(int i=0;i<n;++i)
		{
			scanf("%s",c[i]);
			for(int j=0;j<m;++j)
			{
				mp[i][j]=c[i][j]-'0';
			}
		}		
		for(int i=0;i<n;++i)
		{
			for(int j=m-2;j>=0;--j)
			{
				if(mp[i][j]==0&&mp[i][j+1]==0)a[i][j]+=a[i][j+1]+1;	
			}
		}
		for(int i=0;i<m;++i)
		{
			for(int j=n-3;j>=0;--j)
			{
				if(mp[j][i]==0&&mp[j+1][i]==0&&mp[j+2][i]==0)b[j][i]+=b[j+1][i]+1;
			}
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			{
				for(int k=1;k<=b[i][j];++k)
				{
					ans1+=a[i][j]*a[i+k+1][j];
					ans2+=a[i][j]*a[i+k+1][j]*b[i+k][j];
				}
			}
		}
		printf("%lld %lld\n",e*ans1%998244353,f*ans2%998244353);	
	}
	
}
