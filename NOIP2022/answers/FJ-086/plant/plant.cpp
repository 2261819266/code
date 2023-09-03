#include<iostream>
#include<cstdio>
using namespace std;
int mod=998244353;
int T,id,n,m,c,f;
int Map[2000][2000],Mapx[2000][2000],Mapy[2000][2000],Mapxplas[2000][2000],flag[2000][2000],p[2000][2000][3];
long long ansc,ansf;
int pd(int x)
{
	if (x>0)
		return 1;
	return 0;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	for (int cv=1;cv<=T;cv++)
	{
		cin>>n>>m>>c>>f;
		ansc=0;
		ansf=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=m;j++)
			{
				Map[i][j]=0;
				Mapx[i][j]=0;
				Mapx[n+1][j]=-1;
				Mapy[i][j]=0;
				Mapy[i+1][j]=-1;
				Mapxplas[i][j]=0;
				flag[i][j]=0;
				p[i][j][1]=0;
				p[i][j][2]=0;
			}
			Mapx[i][m+1]=-1;
		}
		for (int i=1;i<=n;i++)
		{
			char a[2000];
			cin>>a;
			for (int j=0;j<=m;j++)
			{
				Map[i][j+1]=a[j]-'0';
				Map[n+1][j+1]=1;
			}
		}
		for (int i=n;i>=1;i--)
			for (int j=m;j>=1;j--)
				if (Map[i][j]==0)
				{
					Mapx[i][j]=Mapx[i][j+1]+1;
					Mapy[i][j]=Mapy[i+1][j]+1;
				}
				else
				{
					Mapx[i][j]=-1;
					Mapy[i][j]=-1;
				}
		for (int i=1;i<=n+1;i++)
			for (int j=1;j<=m;j++)
				if (Map[i][j]==0)
					Mapxplas[i][j]=Mapxplas[i-1][j]+Mapx[i][j];
		for (int i=1;i<=n+1;i++)
			for (int j=1;j<=m;j++)
			{
				if (Map[i][j]==0)
				{
					p[i][j][1]=p[i-1][j][1];
					p[i][j][2]=p[i-1][j][2];
					flag[i][j]=flag[i-1][j];
				}
				else
					ansf=(ansf+flag[i-1][j])%mod;
				if (Mapx[i][j]>0&&p[i-1][j][1]==0)
					p[i][j][1]=i;
				else
					if (Mapx[i][j]>0&&1<Mapy[p[i][j][1]][j]&&Map[i-1][j]==0)
					{
						p[i][j][2]=(p[i-1][j][2]+((Mapxplas[i-2][j]-Mapxplas[p[i][j][1]-1][j])*Mapx[i][j])%mod)%mod;
						flag[i][j]=(flag[i-1][j]+(f*(Mapy[i][j]-Mapy[p[i][j][1]+Mapy[p[i][j][1]][j]][j])*p[i][j][2])%mod)%mod;
					}
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				if (Map[i][j]==0)
					if (Mapy[i][j]>=2)
						ansc=(ansc+(c*((Mapxplas[i+Mapy[i][j]][j]-Mapxplas[i+1][j])%mod)*Mapx[i][j])%mod)%mod;

		cout<<ansc<<" "<<ansf<<endl; 
	}
}
