#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long t,id,n,m,c,f,mod=998244353,a[1099][1099],b[1099][1099][2],sum1,sum2;
char s[9999];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	if(id==1)
	{
		while(t--)
		{
			cin>>n>>m>>c>>f;
			for(int i=1;i<=n;i++)
			{
				cin>>s;
			}
		}
		cout<<0<<" "<<0;
	}
	while(t--)
	{
		cin>>n>>m>>c>>f;
		for(int j=1;j<=m;j++)
		{
			b[n+1][j][0]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			b[i][m+1][1]=-1;
		}
		for(int i=1;i<=n;i++)
		{
			cin>>s;
			for(int j=0;j<m;j++)
			{
				a[i][j+1]=s[j]-'0';
			}
		}
		for(int i=n;i>=1;i--)
		{
			for(int j=m;j>=1;j--)
			{
				if(a[i][j]==1)
				{
					b[i][j][0]=-1;
					b[i][j][1]=-1;
				}
				else
				{
					b[i][j][0]=b[i+1][j][0]+1;
					b[i][j][1]=b[i][j+1][1]+1;
				}
			}
		}
		for(int j=1;j<m;j++)
		{
			for(int i=1;i<n-1;i+=b[i][j][0]+2)
			{
				if(b[i][j][0]<=1)continue;
				long long z=0;
				for(int ii=i+b[i][j][0];ii>=i+2;ii--)
				{
					z+=b[ii][j][1];
					sum1+=z*b[ii-2][j][1];
					sum1=sum1%mod;
				}
				if(b[i][j][0]<=2)continue;
				z=0;
				long long h=0;
				for(int ii=i+b[i][j][0]-1;ii>=i+2;ii--)
				{
					++h;
					z+=b[ii][j][1]*h;
					sum2+=z*b[ii-2][j][1];
					sum2=sum2%mod;
				}
			}
		}
		cout<<(sum1*c)%mod<<" "<<(sum2*f)%mod;
	}
}
