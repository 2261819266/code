#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
const int p=998244353;
const int MAX=1005;
int t,id;
int n,m,c,f;
bool b[MAX][MAX];
int a[2][MAX][MAX];
ll v[2],dp[MAX];
int read()
{
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	return f*s;
}
bool reads()
{
	char c=getchar();
	while((c^'0')&&(c^'1'))
		c=getchar();
	return (c=='1');
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t=read();
	id=read();
	while(t--)
	{
		n=read();
		m=read();
		c=read();
		f=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				b[i][j]=reads();
		for(int i=1;i<=n;i++)
			a[0][i][m+1]=m+1;
		for(int j=1;j<=n;j++)
			a[1][n+1][j]=n+1;
		for(int i=n;i;i--)
			for(int j=m;j;j--)
				if(b[i][j])
				{
					a[0][i][j]=j;//同一行下一个 
					a[1][i][j]=i;//同一列下一个 
				}
				else
				{
					a[0][i][j]=a[0][i][j+1];
					a[1][i][j]=a[1][i+1][j]; 
				}
//		for(int j=1;j<=m;j++)
//		{
//			for(int i=1;i+2<a[1][i][j];i++)
//			{
//				for(int k=i+2;k<a[1][i][j];k++)
//					v[0]=(v[0]+(a[0][i][j]-j-1)*(a[0][k][j]-j-1)%p)%p;
//				for(int k=i+2;k+1<a[1][i][j];k++)
//					v[1]=(v[1]+(a[0][i][j]-j-1)*(a[0][k][j]-j-1)%p*(a[1][i][j]-k-1)%p)%p;
//			}
//		}
		for(int j=1;j<=m;j++)
		{
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++)
			{
				dp[i]=(!b[i][j])*(dp[i-1]+a[0][i][j]-j-1)%p;//cout<<dp[i]<<" "<<a[0][i][j]-j-1<<endl;
				if(i==1)
					continue;
				v[0]=(v[0]+(!b[i][j])*(!b[i-1][j])*dp[i-2]*(a[0][i][j]-j-1)%p)%p;
				v[1]=(v[1]+(!b[i][j])*(!b[i-1][j])*dp[i-2]*(a[0][i][j]-j-1)%p*(a[1][i][j]-i-1)%p)%p;
			}
		}
		v[0]=v[0]*c%p;
		v[1]=v[1]*f%p;
		printf("%d %d\n",(int)v[0]*c,(int)v[1]*f);
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			cout<<a[0][i][j]<<" "<<a[1][i][j]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
