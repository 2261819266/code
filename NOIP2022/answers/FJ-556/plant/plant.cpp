#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int id,T,n,m,c,f,a[1010][1010],cc[1010][1010],ff[1010][1010],s[1010][1010],ansf,ansc;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	for(int i=0;i<T;i++)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++)
				scanf("%d",&a[j][k]);
		for(int j=1;j<=n;j++)
		{
			int t=0;
			for(int k=m;k>=1;k--)
			{
				if(a[j][k]==0)
				{
					cc[j][k]=t;
					t++;
				}
				else t=0;
			}
		}
		for(int k=1;k<=m;k++)
		{
			int t=0;
			for(int j=n;j>=1;j--)
			{
				if(a[j][k]==0)
				{
					ff[j][k]=t;
					t++;
				}
				else t=0;
			}
		}
		for(int k=1;k<=m;k++)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j][k]==1)
				{
					s[j+1][k]=0;
					s[j+2][k]=0;
				}
				else
				{
					if(cc[j][k]!=0&&c!=0)
					{
						int t=cc[j][k]*s[j][k]%mod;
						ansc+=t;
						if(f!=0)ansf+=ff[j][k]*t%mod;
					}
					s[j+1][k]=s[j][k]+cc[j-1][k];
				}
			}
		}
		cout<<ansc<<" "<<ansf<<endl;
	}
	return 0;
}
