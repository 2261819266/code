#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
bool ok[1001][1001];
long long r[1001][1001],sr[1001][1001];//right
long long srd[1001][1001];//right & down
long long d[1001][1001];//down
int n,m;
long long cc,ff;
const long long mod=998244353;
char s[10001];
void makegraph()
{
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)
		{
			if(s[j]=='0')ok[i][j]=true;
			else ok[i][j]=false;
		}
	}
}
void getr()
{
	for(int i=1;i<=n;i++)
	{
		r[i][m]=0;
		for(int j=m-1;j>0;j--)
		{
			if(ok[i][j]==false||ok[i][j+1]==false)r[i][j]=0;
			else r[i][j]=r[i][j+1]+1;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)sr[i][j]=sr[i-1][j]+r[i][j];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)printf("%lld ",sr[i][j]);
//		printf("\n");
//	}
}
void getd()
{
	for(int j=1;j<=m;j++)
	{
		d[n][j]=0;
		for(int i=n-1;i>0;i--)
		{
			if(ok[i][j]==false||ok[i+1][j]==false)d[i][j]=0;
			else d[i][j]=d[i+1][j]+1;
		}
	}
//		for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++)printf("%lld ",d[i][j]);
//		printf("\n");
//	}
}
void getrd()
{
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			srd[i][j]=srd[i-1][j]+r[i][j]*d[i][j];
			srd[i][j]%=mod;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)printf("%lld ",srd[i][j]);printf("\n");
//	}
}
long long crt(long long x){return (x%mod+mod)%mod;}
long long calcc()
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(r[i][j]==0)continue;
			int furt=i+(int)d[i][j];
			if(furt<=i+1)continue;
			ans=(ans+r[i][j]*crt(sr[furt][j]-sr[i+1][j]))%mod;
		}
	}
	return ans;
}
long long calcf()
{
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(r[i][j]==0)continue;
			int furt=i+(int)d[i][j];
			if(furt<=i+1)continue;
			ans=(ans+r[i][j]*crt(srd[furt][j]-srd[i+1][j]))%mod;
		}
	}
	return ans;
}
void work()
{
	scanf("%d%d",&n,&m);
	scanf("%lld%lld",&cc,&ff);
	makegraph();
	getr();getd();getrd();
	long long ansc=calcc();
	long long ansf=calcf();
	printf("%lld %lld\n",((ansc*cc)%mod),(ansf*ff)%mod);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	for(int i=1;i<=T;i++)work();
	return 0;
}
/*
3 0 
4 3 1 1
001
010
000
000
6 6 1 1
000010
011000
000110
010000
011000
000000
16 12 1 1
000000000001
011111111111
000000000011
011111111111
010011111111
010111100011
010011101111
011111100011
111111111111
000011111111
011111111111
000000111111
011111000111
011111011111
011111000111
011111011111

Oh, my dear CCF, can you explain why the third sample is so noisome
*/
