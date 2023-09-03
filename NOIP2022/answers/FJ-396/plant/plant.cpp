#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005,mod=998244353;
int t,n,m,c,f,id,a[N][N],lft[N][N],dwn[N][N],cnt1[N][N],cnt2[N][N];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>t>>id;
	while(t--)
	{
		cin>>n>>m>>c>>f;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%1d",&a[i][j]);
		if(id==1)
		{
			puts("0");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int tmp=-1;
			for(int j=m;j>=1;j--)
				if(!a[i][j]) lft[i][j]=++tmp;
				else lft[i][j]=tmp=-1;
		}
		for(int j=1;j<=m;j++)
		{
			int tmp=-1;
			for(int i=n;i>=1;i--)
			{
				if(!a[i][j]) dwn[i][j]=++tmp;
				else dwn[i][j]=tmp=-1;
				if(!a[i][j]&&!a[i+1][j]&&!a[i+2][j]) 
				{
					cnt1[i][j]=(cnt1[i+1][j]+lft[i+2][j])%mod;
					cnt2[i][j]=(cnt2[i+1][j]+((ll)lft[i+2][j]*dwn[i+2][j])%mod)%mod;
				}
				else 
				{
					cnt1[i][j]=0;
					cnt2[i][j]=0;
				}
			}
		}
		int vc=0,vf=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				vc=(vc+((ll)lft[i][j]*cnt1[i][j])%mod)%mod,
				vf=(vf+((ll)lft[i][j]*cnt2[i][j])%mod)%mod;
		cout<<vc*c<<' '<<vf*f<<endl;
	}
	return 0;
}
