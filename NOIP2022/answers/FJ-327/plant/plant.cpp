#include<bits/stdc++.h>
#define fio(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
using namespace std;
const int N=1005;
const long long mod=998244353;
int t,id;
int n,m,c,f;
char a[N][N];
long long vx[N][N],vy[N][N],sumx[N][N],sumy[N][N],ssumy[N][N];
long long cans,fans;
void init()
{
	memset(vx,0,sizeof vx);
	memset(vy,0,sizeof vy);
	memset(sumx,0,sizeof sumx);
	memset(sumy,0,sizeof sumy);
	memset(ssumy,0,sizeof ssumy);
	cans=0,fans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=1;
		while(l!=m+1||r!=m+1)
		{
			while(a[i][l]=='1')
				vx[i][l]=0,l++;
			if(l==m+1) break;
			if(r<l) r=l;
			while(a[i][r]=='0') r++;
			vx[i][l]=r-l;
			l++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int l=1,r=1;
		while(l!=n+1||r!=n+1)
		{
			while(a[l][i]=='1')
				vy[l][i]=0,l++;
			if(l==n+1) break;
			if(r<l) r=l;
			while(a[r][i]=='0') r++;
			vy[l][i]=r-l;
//			printf("vy[%d][%d]=%d-%d=%lld\n",l,i,r,l,vy[l][i]);
			l++;
		}
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		sumx[i][j]=sumx[i][j-1]+vx[i][j]-1;
		sumy[i][j]=sumy[i-1][j]+vx[i][j]-1;
		ssumy[i][j]=ssumy[i-1][j]+sumy[i][j];
//		printf("vx[%d][%d]=%lld,vy[%d][%d]=%lld\n",i,j,vx[i][j],i,j,vy[i][j]);
	}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		memset(a,0,sizeof a);
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=1;i<=n;i++)
			scanf("%s",a[i]+1);
		init();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vy[i][j]>=3) cans=(cans+(vx[i][j]-1)*(sumy[i+vy[i][j]-1][j]-sumy[i+1][j]))%mod;
				if(vy[i][j]>=4) fans=(fans+(vx[i][j]-1)*(ssumy[i+vy[i][j]-2][j]-ssumy[i+1][j]-(vy[i][j]-3)*sumy[i+1][j]))%mod;
			}
		}
		printf("%lld %lld\n",(long long)c*cans%mod,(long long)f*fans%mod);
	}
	
	return 0;
}
/*
maybe I can get 100pts !!!! \CXL/ \CXL/ \CXL/


plant3.ans:114 514 Cao
*/
