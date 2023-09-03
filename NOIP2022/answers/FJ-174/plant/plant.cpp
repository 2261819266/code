#include<bits/stdc++.h>
using namespace std;
int n,m,cc,ff;
long long ansc,ansf;
int t,id;
char cs;
long long a[1010][1010];
long long b[1010][1010];
long long c[1010][1010];
long long f[1010][1010];
long long e[1010][1010];
long long h=998244353;
int main()
{
  freopen("plant.in","r",stdin);
  freopen("plant.out","w",stdout);
  cin>>t>>id;
  for(int l=1;l<=t;l++)
  {
	scanf("%d%d%d%d",&n,&m,&cc,&ff);
	ansc=ansf=0;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(e,0,sizeof(e));
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=m;j++)
	  {
	    cin>>cs;
	    if(cs=='1') a[i][j]=1;
	  }
	  for(int j=m;j>=1;j--)
	    if(a[i][j]==0)
	      b[i][j]=b[i][j+1]+1;
	}
	for(int i=1;i<=m;i++)
	  for(int j=n;j>=1;j--)
	    if(a[j][i]==0)
	      c[j][i]=c[j+1][i]+1;
	for(int j=1;j<=m;j++)
	  for(int i=n;i>=1;i--)
	    if(a[i][j]==0)
	      f[i][j]=f[i+1][j]+b[i][j]-1;
	for(int j=1;j<=m;j++)
	  for(int i=n-1;i>=1;i--)
	    if(a[i][j]==0)
	      e[i][j]=e[i+1][j]+(b[i][j]-1)*(c[i][j]-1);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	    if(b[i][j]>=2&&c[i][j]>=3)
	    {
	      int k=i+2;
	      ansc+=(b[i][j]-1)*f[k][j];
		}
		if(b[i][j]>=2&&c[i][j]>=4)
		{
		  int k=i+2;
		  if(a[k][j]==1)
			break;
		  ansf+=(b[i][j]-1)*e[k][j];  
		}
	  }
	printf("%lld %lld",(ansc*cc)%h,(ansf*ff)%h);
  }
  return 0;
}
