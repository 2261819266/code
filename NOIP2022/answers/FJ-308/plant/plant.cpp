#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<queue>
#define fru(i,j,k) for(register int i=j;i<=k;i++)
#define frd(i,j,k) for(register int i=j;i>=k;i--)
#define pc(x) putchar(x)
#define finfout(x) freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);
char c=' ';
long long in(void)
{
	long long x=0;bool f=false;
	while(!isdigit(c))
	{
		f|=c=='-';
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f?-x:x;
}
template<typename t>
void out(t x)
{
	if(x<0)pc('-'),x=-x;
	if(x>9)out(x/10);
	pc(x%10+'0');
}
using namespace std;
const int maxn=1012;
using ll = long long;
const ll mod=998244353;
int t,id,n,m;
ll C,F,nl[maxn][maxn],ml[maxn][maxn],zh[maxn][maxn],ctmp[maxn][maxn],ansc,ansf;
char ch[maxn][maxn];
int main()
{
	finfout(plant);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		memset(nl,0,sizeof nl);memset(zh,0,sizeof zh);memset(ctmp,0,sizeof ctmp);memset(ml,0,sizeof ml);
		scanf("%d%d%lld%lld",&n,&m,&C,&F);
		fru(i,1,n)scanf("%s",ch[i]+1);
		fru(i,1,n)
		frd(j,m,1)
		nl[i][j]=(ch[i][j]=='0'?nl[i][j+1]+1:0)%mod;
		frd(i,n,1)
		fru(j,1,m)
		ml[i][j]=(ch[i][j]=='0'?ml[i+1][j]+1:0)%mod;
//		fru(i,1,n)
//		{
//		fru(j,1,m)
//		{
//			cout<<nl[i][j]<<' ';
//		}	cout<<endl;
//		}
		fru(i,2,n)fru(j,1,m-1)
		if(ch[i][j]=='0'&&ch[i-1][j]=='0')
		(zh[i][j]+=zh[i-1][j]+nl[i-1][j+1])%=mod;
//		fru(i,1,n)
//		{
//		fru(j,1,m)
//		{
//			cout<<zh[i][j]<<' ';
//		}	cout<<endl;
//		}
		fru(i,3,n)fru(j,1,m-1)
		{
		(ctmp[i][j]=nl[i][j+1]*zh[i-1][j]%mod+ctmp[i-1][j])%=mod;
		(ansc+=nl[i][j+1]*zh[i-1][j]%mod)%=mod;
		}
		
		fru(i,3,n-1)fru(j,1,m-1)
		if(ch[i][j]=='0')
		{
			(ansf+=nl[i][j+1]*zh[i-1][j]*ml[i+1][j])%=mod;
		}
		out((ansc*C)%mod);pc(' ');out((ansf*F)%mod);pc('\n');
	}
	return 0;
}
/*
input:
1 0
4 3 1 1
001
010
000
000
output:
4 2
*/
