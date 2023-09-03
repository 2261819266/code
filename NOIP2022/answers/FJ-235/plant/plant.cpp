#include<bits/stdc++.h>
using namespace std;
int T,id;
int l[1050],h[1050][1050];
int Mod=998244353;
int n,m,c,f;
char a[1050][1050];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{

		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++)//确定横向长度 
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]=='0')
				{
					int k=j+1;
					while(a[i][k]=='0'&&k<=m)
					{
						if(a[i][k]=='0')
							h[i][j]++;
						k++;	
					}
				}
			}
		}
		int ansc=0,ansf=0;
		for(int j=1;j<=m;j++)//列 
		{
			for(int i=1;i<=n-2;i++)//行 
			{
				if(a[i][j]=='0'&&a[i+1][j]=='0')
				{
					if(h[i][j]>0)
					{
						for(int k=i+2;k<=n;k++)
						{
							if(h[k][j]>0&&a[k][j]=='0')
							{
								ansc+=(h[i][j]*h[k][j])%Mod;
								if(a[k+1][j]=='0'&&((k+1)<=n))
									ansf+=(h[i][j]*h[k][j])%Mod;
							}
						}
					}
				}
			}
		}
		ansc=ansc%Mod;
		ansf=ansf%Mod;
		ansc*=c;
		ansf*=f;
		printf("%d %d",ansc,ansf);
	}
	return 0;
}
