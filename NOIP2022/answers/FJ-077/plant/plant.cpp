#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
long long t,n,m,id,c,f;
long long ansc,ansf,ans;
char pp[10001];
long long a[1051][1051];
long long h[1051][1051];
long long l[1051][1051];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id; 
	while(t--)
	{
		ansc=0;
		ansf=0;
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(int i=1; i<=n; i++)
		{
			cin>>pp;
			for(int j=0; j<m; j++)
			{
				if(pp[j]=='0')
				{
					a[i][j+1]=0;
				}
				else
				{
					a[i][j+1]=1;
				}
			}
		}
		for(int i=0; i<=n+1; i++)
		{
			for(int j=0; j<=m+1; j++)
			{
				h[i][j]=0;
				l[i][j]=0;
			}
		}
		for(int i=1; i<=n; i++)
		{
			for(int j=m; j>=1; j--)
			{
				if(a[i][j]==0)
				{
					h[i][j]=h[i][j+1]+1;
				}
			}
		}
		for(int i=1; i<=m; i++)
		{
			for(int j=n; j>=1; j--)
			{
				if(a[j][i]==0)
				{
					l[j][i]=l[j+1][i]+1;
					//cout<<999;
				}
			}
		}
	/*	for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				cout<<l[i][j]<<" ";
			}
			cout<<endl;
		}*/
		for(int i=1; i<=m; i++)
		{
			if(c==0)
			{
				break;
			}
			for(int j1=1; j1<=n; j1++)
			{
				if(h[j1][i]<=1)
				{
					continue;
				}
				for(int j2=j1+2; j2<=n; j2++)
				{
					if(l[j1][i]<j2-j1+1)
					{
						break;
					}
					if(h[j2][i]<=1)
					{
						continue;
					}
					ans=(h[j1][i]-1)*(h[j2][i]-1);
					ans%=998244353;
					ansc+=ans;
					ansc%=998244353;
					//cout<<"i:"<<i<<" j1:"<<j1<<" j2:"<<j2<<" ans:"<<ansc<<endl;
				}
			}
		}
		for(int i=1; i<=m; i++)
		{
			if(f==0)
			{
				break;
			}
			for(int j1=1; j1<=n; j1++)
			{
				if(h[j1][i]<=1)
				{
					continue;
				}
				for(int j2=j1+2; j2<=n; j2++)
				{
					if(l[j1][i]<=j2-j1+1)
					{
						break;
					}
					if(h[j2][i]<=1)
					{
						continue;
					}
					ans=(h[j1][i]-1)*(h[j2][i]-1)*(l[j1][i]-j2+j1-1);
					ans%=998244353;
					ansf+=ans;
					ansf%=998244353;
				}
			}
		}
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
} 
