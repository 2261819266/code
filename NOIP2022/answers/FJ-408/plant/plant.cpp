#include<bits/stdc++.h>
using namespace std;
int mod=998244353,t,id,n,m,c,f;
char a[1005][1005];
int lie[1005][1005],hang[1005][1005];
int main()
{
//	freopen("plant.in","r",stdin);
//	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
		if(c==0&&f==0)
		{
			printf("0 0\n");
			continue;
		}
		memset(lie,0,sizeof(lie));
		memset(hang,0,sizeof(hang));
		for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			if(a[i][j+1]=='0'&&a[i][j]=='0')
				hang[i][j]=hang[i][j+1]+1;
			else
				hang[i][j]=0;
		for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			if(a[i][j]=='0')
				lie[i][j]=lie[i-1][j]+1;
			else
				lie[i][j]=0;
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
				hang[j][i]=(hang[j][i]+hang[j-1][i])%mod;
		long long sc=0,sf=0;
		if(c!=0)
		{
			for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=n;k>=i+2;k--)
				{
					if(lie[k][j]-lie[i][j]==k-i)
					{
						sc=(sc+((hang[i][j]-hang[i-1][j])%mod*(hang[k][j]-hang[i+1][j])%mod)%mod)%mod;
						break;
					}
				}
		}
		printf("%d ",sc*c%mod);
		if(f!=0)
		{
			for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int k=i+3;k<=n;k++)
					if(lie[k][j]-lie[i][j]==k-i)
						sf=(sf+((hang[i][j]-hang[i-1][j])%mod*(hang[k-1][j]-hang[i+1][j])%mod)%mod)%mod;
					else
						break;
		}
		printf("%d\n",sf*f%mod);
	}
	return 0;
}