#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10,mod=998244353;
int n,m,c,f;
char a[MAXN][MAXN];
int ri[MAXN][MAXN],upp[MAXN][MAXN],dow[MAXN][MAXN]; //向右，向上，向下 
int pre[MAXN][MAXN]; //每一列上向右扩展格子数的前缀和 
int ansc,ansf;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id; scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++) 
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		for(int i=1;i<=n;i++) //right
		{
			if(a[i][m]=='0') ri[i][m]=1;
			else ri[i][m]=0;
			for(int j=m-1;j>=1;j--)
				if(a[i][j]=='1') ri[i][j]=0;
				else ri[i][j]=ri[i][j+1]+1;
		}
		for(int j=1;j<=m;j++) //up
		{
			if(a[1][j]=='0') upp[1][j]=1;
			else upp[1][j]=0;
			for(int i=2;i<=n;i++)
				if(a[i][j]=='1') upp[i][j]=0;
				else upp[i][j]=upp[i-1][j]+1;
		}
		for(int j=1;j<=m;j++) //down
		{
			if(a[n][j]=='0') dow[n][j]=1;
			else dow[n][j]=0;
			for(int i=n-1;i>=1;i--)
				if(a[i][j]=='1') dow[i][j]=0;
				else dow[i][j]=dow[i+1][j]+1;
		}
		for(int j=1;j<=m;j++) //pre
		{
			pre[0][j]=0;
			for(int i=1;i<=n;i++)
				pre[i][j]=pre[i-1][j]+ri[i][j];
		}
		ansc=0;
		for(int i=1;i<=n;i++) //x1
			for(int j=1;j<=m;j++) //y0
				if(ri[i][j]>=2&&dow[i][j]>=3)
				{
					ansc+=1ll*(ri[i][j]-1)*(pre[i+dow[i][j]-1][j]-pre[i+1][j]-dow[i][j]+2)%mod;
					if(ansc>=mod) ansc-=mod;
				}
		ansf=0;
		for(int i=1;i<=n;i++) //x2
			for(int j=1;j<=m;j++) //y0
				if(ri[i][j]>=2&&upp[i][j]>=3&&dow[i][j]>=2)
				{
					ansf+=1ll*(ri[i][j]-1)*(pre[i-2][j]-pre[i-upp[i][j]][j]-upp[i][j]+2)%mod*(dow[i][j]-1)%mod;
					if(ansf>=mod) ansf-=mod;
				}
		printf("%d %d\n",ansc,ansf);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
