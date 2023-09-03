#include<bits/stdc++.h>
const int P=998244353;
const int N=1e3+99;
using namespace std;
int n,m,c,f,T,id,a[N][N],b[N][N];
int ansc,ansf,ans[N],sum[N];
char s[N][N];
inline void solvec(int x,int y)
{
	memset(ans,0,sizeof(ans));
	int t=a[x][y]-1,cnt=0;
	for(int i=2;a[x+i][y]!=0;i++)
	{
		ans[++cnt]=t*(a[x+i][y]-1);
		sum[cnt]=b[x+i][y];
	}
	for(int i=1;i<=cnt;i++)
	{
		ansc=(ansc+ans[i])%P;
		ansf=i==cnt?ansf:(ansf+ans[i]*(sum[i]-1))%P;
	}
	return;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0)
		{
			printf("0 0\n");
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>s[i][j];
		for(int i=1;i<=n;i++)
			for(int j=m;j>0;j--)
				if(s[i][j]=='0')
					a[i][j]=a[i][j+1]+1;
		for(int i=1;i<=m;i++)
			for(int j=n;j>0;j--)
				if(s[j][i]=='0')
					b[j][i]=b[j+1][i]+1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]>=2&&b[i][j]>=3)
					solvec(i,j);
		printf("%d %d\n",ansc*c,ansf*f);
	}
	return 0;
}
