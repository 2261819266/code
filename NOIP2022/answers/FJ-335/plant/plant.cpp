#include<bits/stdc++.h>
#define mod 998244353
int T,id;
int n,m,c,f,ansc,ansf;
int a[1005][1005];
void work(int x1,int x2,int y0)
{
	int y1=0,y2=0,sum;
	for(int i=y0+1;i<=m&&(!a[x1][i]);i++)
		y1=(y1+1)%mod;
	for(int i=y0+1;i<=m&&(!a[x2][i]);i++)
		y2=(y2+1)%mod;
	sum=y1*y2%mod;
	ansc=(ansc+sum)%mod;
	if(f)
	{
		for(int x3=x2+1;x3<=n;x3++)
		{
			if(!a[x3][y0])ansf=(ansf+sum)%mod;
			else break;
		}
	}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				char ch;
				scanf("%c",&ch);
				if(ch=='0')a[i][j]=0;
				else if(ch=='1')a[i][j]=1;
				else j--;
			}
		}
		ansc=ansf=0;
		if(c)
		{
			for(int x1=1;x1<=n;x1++)
				for(int y0=1;y0<=m;y0++)
				{
					if((!a[x1][y0])&&(!a[x1+1][y0]))
						for(int x2=x1+2;x2<=n&&(!a[x2][y0]);x2++)
							work(x1,x2,y0);
				}
		}
		printf("%d %d\n",ansc*c%mod,ansf*f%mod);
	}
	return 0;
}
