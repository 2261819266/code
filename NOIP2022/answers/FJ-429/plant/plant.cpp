#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 1250;
const long long mod = 998244353ll;
int T,id;
int n,m;
long long c,f;
long long C[N][N],F[N][N];
long long sum[N][N];
int lash[N][N],lass1[N][N],lass2[N][N];//1 qian 2 hou
char str;
bool keng[N][N];
long long ansc=0,ansf=0;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%lld%lld",&n,&m,&c,&f);
		ansc=0;
		ansf=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				str=getchar();
				while(str<'0'||str>'1') str=getchar();
				if(str=='0') keng[i][j]=true;
				else keng[i][j]=false;
			}
		int las;	
		for(int j=1;j<=m;j++)
		{
			las=n;
			for(int i=n;i>=1;i--){
				if(keng[i][j]==false) las=i-1;
				lass2[i][j]=las;
			}
			las=1;
			for(int i=1;i<=n;i++)
			{
				if(keng[i][j]==false) las=i+1;
				lass1[i][j]=las;
			}
		}
		for(int i=1;i<=n;i++)
		{
			las=m;
			for(int j=m;j>=1;j--)
			{
				if(keng[i][j]==false) las=j-1;
				lash[i][j]=las;
			}
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				sum[j][i]=sum[j-1][i]+((keng[j][i]==false)?0:(lash[j][i]-i));
		for(int i=3;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(keng[i][j]==false) continue;
				C[i][j]=max(sum[i-2][j]-sum[lass1[i][j]-1][j],0ll)*max(lash[i][j]-j,0);
				C[i][j]%=mod;
				ansc+=C[i][j];
				ansc%=mod;		
			}
		}
		for(int i=3;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(keng[i][j]==false) continue;
				F[i][j]=C[i][j]*max(lass2[i][j]-i,0);
				F[i][j]%=mod;
				ansf+=F[i][j];
				ansf%=mod;
			}
		printf("%lld %lld\n",c*ansc,f*ansf);
	}
	return 0;
}

