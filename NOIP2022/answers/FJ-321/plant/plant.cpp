#include<bits/stdc++.h>
using namespace std;
int mod=998244353,id,t,n,m,c,f,x[5],y[5],ansc,ansf;
char ch;
bool a[1010][1010];
bool checkc(int q)
{
	for(int i=y[0];i<=y[1];i++)
	{
		if(a[x[1]][i])
		{
			return false;
		}
	}
	for(int i=y[0];i<=y[2];i++)
	{
		if(a[x[2]][i])
		{
			return false;
		}
	}
	for(int i=x[1];i<=x[q];i++)
	{
		if(a[i][y[0]])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		ansc=ansf=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>ch;
				a[i][j]=ch-'0';
			}
		}
		if(id==1)
		{
			printf("0 0\n");
			continue;
		}
		if(c)
		{
			for(x[1]=1;x[1]<n-1;x[1]++)
			{
				for(x[2]=x[1]+2;x[2]<=n;x[2]++)
				{
					for(y[0]=1;y[0]<m;y[0]++)
					{
						for(y[1]=y[0]+1;y[1]<=m;y[1]++)
						{
							for(y[2]=y[0]+1;y[2]<=m;y[2]++)
							{
								if(checkc(2))
								{
									ansc++;
								}
							}
						}
					}
				}
			}
		}
		if(f)
		{
			for(x[1]=1;x[1]<n-2;x[1]++)
			{
				for(x[2]=x[1]+2;x[2]<n;x[2]++)
				{
					for(x[3]=x[2]+1;x[3]<=n;x[3]++)
					{
						for(y[0]=1;y[0]<m;y[0]++)
						{
							for(y[1]=y[0]+1;y[1]<=m;y[1]++)
							{
								for(y[2]=y[0]+1;y[2]<=m;y[2]++)
								{
									if(checkc(3))
									{
										ansf++;
									}
								}
							}
						}
					}
				}
			}
		}
		printf("%d %d\n",c*ansc,f*ansf);
	}
	return 0;
}
