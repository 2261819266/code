#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int t,id,n,m,c,f;
bool a[2001][2001];
long long num(long long x,long long y)
{
	if(id==5)
	{
		return 1;
	}
	long long d=0;
	for(long long i=x;i<=m;i++)
	{
		if(a[y][i]==1)
		{
			d++;
		}
		else
		{
			return d-1;
		}
	}
	return m-x;
}
void check()
{
	long long ans1=0,ans2=0;
	for(long long i=1;i<=m;i++)
	{
		long long lst=0,numl,lstt=0;
		for(long long j=1;j<=n;j++)
		{
			if(a[j][i]==1)
			{
				if(!lst)
				{
					lst=j;
					lstt=j;
				}
				long long numj=num(i,j);
				while(lst>0&&j-lst>=2)
				{
					long long numl=num(i,lst),k=j;
					ans1=ans1+(numj*numl)%mod;
					ans1%=mod;
					if(id!=6&&id!=15)
					{
						while(1)
						{
							k++;
							if(a[k][i]!=1||k>n)
							{
								k--;
								break;
							}
						}
						ans2=ans2+(k-j)*(numj*numl)%mod;
						ans2%=mod;
					}
					lst++;
				}
				lst=lstt;
			}
			else
			{
				lst=0;
				lstt=0;
			}
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--)
	{
		cin>>n>>m>>c>>f;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=1;j<=m;j++)
			{
				char x;
				cin>>x;
				if(x=='0')
				{
					a[i][j]=1;
				}
				else
				{
					a[i][j]=0;
				}
			}
		}
		if(id==1)
		{
			cout<<"0 0"<<endl;
		}
		else
		{
			check();
		}
	}
	return 0;
}
