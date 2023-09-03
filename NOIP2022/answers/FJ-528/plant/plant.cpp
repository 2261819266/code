#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long n,m,c,f,a[1005][1005],x[1005][1005],y[1005][1005],i,j,sc,sf,id,T,k,s;
char t;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--)
	{
		cin>>n>>m>>c>>f;
		sc=sf=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				cin>>t;
				a[i][j]=t-'0';
			}
		}
		for(i=1;i<=n;i++)
		y[i][m]=0;
		for(i=1;i<=m;i++)
		x[n][i]=0;
		for(i=1;i<=n;i++)
		{
			for(j=m-1;j>=1;j--)
			{
				if(a[i][j]==1)
				{
					y[i][j]=0;
					continue;
				}
				if(a[i][j+1]==1)
				y[i][j]=0;
				else y[i][j]=y[i][j+1]+1;
			}
		}
		for(i=1;i<=m;i++)
		{
			for(j=n-1;j>=1;j--)
			{
				if(a[j][i]==1)
				{
					x[j][i]=0;
					continue;
				}
				if(a[j+1][i]==1)
				x[j][i]=0;
				else x[j][i]=x[j+1][i]+1;
			}
		}
		for(j=1;j<=m-1;j++)
		{
			s=0;
			for(i=n;i>=3;i--)
			{
				if(a[i][j]==1)
				s=0;
				else 
				{
					s+=y[i][j];
					if(a[i-1][j]==0&&a[i-2][j]==0)
					sc=(sc+s*y[i-2][j])%p;
					//cout<<i<<" "<<j<<" "<<s<<" "<<sc<<endl;
				}
			}
		}
		for(j=1;j<=m-1;j++)
		{
			s=0;
			for(i=n-1;i>=3;i--)
			{
				if(a[i][j]==1)
				s=0;
				else 
				{
					s+=y[i][j]*x[i][j];
					if(a[i-1][j]==0&&a[i-2][j]==0)
					sf=(sf+s*y[i-2][j])%p;
				}
			}
		}
		sc=sc*c%p;
		sf=sf*f%p;
		cout<<sc<<" "<<sf<<endl;
	}
	return 0;
}
