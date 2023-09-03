#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
const int N=1009,mod=998244353,inv2=499122177;
char a[N][N];
int n,m,c,f;
int b[N][N];
void readIn()
{
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
	for(int i=1;i<=n;i++)
	scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++)
	for(int j=m;j>=1;j--)
	{
		if(a[i][j]=='0') b[i][j]=b[i][j+1]+1;
		else b[i][j]=0;
	}
}
int tj[N];
int c1[N],c2[N];
int ansc=0,ansf=0;
void getans()
{
	ansc=0;ansf=0;
	tj[0]=0;
	for(int j=1;j<=m;j++)
	{
		a[n+1][j]='1';
		for(int i=1;i<=n+1;i++)
		if(a[i][j]=='0') tj[++tj[0]]=b[i][j+1];
		else
		{
			c1[tj[0]+1]=c2[tj[0]+1]=0;
			for(int k=tj[0];k>=1;k--) c1[k]=(c1[k+1]+tj[k])%mod,c2[k]=(c2[k+1]+tj[k]*(tj[0]-k)%mod)%mod;
			for(int k=1;k+2<=tj[0];k++) ansc=(ansc+tj[k]*c1[k+2]%mod)%mod,ansf=(ansf+tj[k]*c2[k+2]%mod)%mod;
			tj[0]=0;
		}
	}
}
void work()
{
	readIn();
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++) cout<<b[i][j]<<" ";
//		cout<<endl;
//	}
	getans();
	printf("%lld %lld\n",c*ansc%mod,f*ansf%mod);
}
signed main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%lld%lld",&T,&id);
	while(T--) work();
}
