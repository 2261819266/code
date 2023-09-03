#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mod 998244353 
using namespace std;
int n,m,pct[1145][1400]={0},t,s,c,f,p,o,q,l=0,r=0,dis[1145][1400]={0};;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&s,&t);
	while(s--)
	{
		memset(pct,0,sizeof(pct));
		memset(dis,0,sizeof(dis));
		scanf("%d%d%d%d%*c",&n,&m,&c,&f);
		p=1,l=0,r=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%c",&pct[i][j]);
				pct[i][j]-=48;
				if(pct[i][j]==1)
				{
					for(int k=j-2;k>=1;k--)
					{
						if(pct[i][k]==1)break;
						dis[i][k]=dis[i][k+1]+1;
					}
				}
			}
			scanf("%*c");
		}
		for(int i=1;i<=n;i++)
		{
			if(dis[i][m]==0 && pct[i][m]!=1)
			{
				for(int k=m-1;k>=1;k--)
				{
					if(pct[i][k]==1)break;
					dis[i][k]=dis[i][k+1]+1;	
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(pct[i][j]==1 || pct[i][j+1]==1 || pct[i+1][j]==1)continue;
				o=dis[i][j];
				for(int p=i+2;p<=n && pct[p][j]!=1;p++)
				{
					q=dis[p][j];
					l+=q*o;
					l%=mod;
					if(p<n)
					{
						r+=q*o;
						r%=mod;
					}
				}
			}
		}
		printf("%d %d\n",l*c%mod,r*f%mod);
	}
	
}
/*
2 0
4 4 1 1
0000
0100
0000
0000
4 3 1 1
001
010
000
000
*/
