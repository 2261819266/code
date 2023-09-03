#include<bits/stdc++.h>
#define P 998244353
using namespace std;
int t,id,n,m,c,f,i,j,x,y,xx;
int a[1010][1010],dwn[1010][1010],p[1010][1010],lft[1010][1010];
long long cc,ff;
long long qj1[1010][1010],qj2[1010][1010];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--)
	{
		cc=ff=0;
		cin>>n>>m>>c>>f;
		for(i=1;i<=m;i++)
		{
			a[0][i]=a[n+1][i]=1;
			dwn[0][i]=dwn[n+1][i]=p[0][i]=p[n+1][i]=lft[0][i]=lft[n+1][i]=0;
		}
		for(i=1;i<=n;i++)
		{
			a[i][0]=a[i][m+1]=1;
			dwn[i][0]=dwn[i][m+1]=p[i][0]=p[i][m+1]=lft[i][0]=lft[i][m+1]=0;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%1d",&a[i][j]);
				dwn[i][j]=(a[i][j]?0:dwn[i-1][j]+1);
			}
		}
		for(i=n;i>=1;i--)
		{
			for(j=m;j>=1;j--)
			{
				p[i][j]=((a[i][j]||a[i+1][j])?0:p[i+1][j]+1);
				lft[i][j]=((a[i][j]||a[i][j+1])?0:lft[i][j+1]+1);
			}
		}
		for(i=1;i<=m;i++)
		{
			qj1[n][i]=(a[n][i]?0:lft[n][i]);
			qj2[n][i]=(a[n][i]?0:lft[n][i]*p[n][i]);
		}
		for(i=n-1;i>=1;i--)
		{
			for(j=1;j<=m;j++)
			{
				qj1[i][j]=(a[i][j]?0:lft[i][j]+qj1[i+1][j]);
				qj2[i][j]=(a[i][j]?0:lft[i][j]*p[i][j]+qj2[i+1][j]);
			}
		}
		for(x=1;x<=n-2;x++)
		{
			for(y=1;y<m;y++)
			{
				if(dwn[x+2][y]-dwn[x][y]!=2)	continue;
				cc=(cc+qj1[x+2][y]*lft[x][y])%P;
				ff=(ff+qj2[x+2][y]*lft[x][y])%P;
			}
		}
		cout<<cc*c<<' '<<ff*f;
		puts(" ");
	}
	return 0;
}
