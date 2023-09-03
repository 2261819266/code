#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+5, P = 998244353;
int n,m,c,f;
char s[N][N];
int nxtr[N][N],nxtc[N][N];
void init()
{
	for(int i=1; i<=n; i++)
	{
		int lst=m+1;
		for(int j=m; j; j--) 
		{
			if(s[i][j]=='1') lst=j;
			nxtr[i][j]=lst;
		}
	}
	for(int i=1; i<=m; i++)
	{
		int lst=n+1;
		for(int j=n; j; j--)
		{
			if(s[j][i]=='1') lst=j;
			nxtc[j][i]=lst;
		}
	}
	/*for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++) printf("%d ",nxtr[i][j]);
		puts("");
	}
	puts("---");
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++) printf("%d ",nxtc[i][j]);
		puts("");
	}
	puts("---");*/
}	
int p[N],q[N],tmpc[N],tmpf[N];
void work()
{
	ll ansc=0,ansf=0;
	for(int j=1; j<=m; j++)
	{
		for(int i=1; i<=n; i++)	p[i]=nxtr[i][j]-j-1;
		for(int i=1; i<=n; i++) q[i]=nxtc[i][j]-i-1;
//		printf("j=%d\n",j);
//		for(int i=1; i<=n; i++) printf("%d ",p[i]); puts("");
//		for(int i=1; i<=n; i++) printf("%d ",q[i]); puts("");
		for(int i=n; i; i--)
		{
			if(s[i][j]=='1') tmpc[i]=tmpf[i]=0;
			else
			{
				tmpc[i]=(tmpc[i+1]+p[i])%P;
				tmpf[i]=(tmpf[i+1]+(ll)p[i]*q[i])%P;
			}
		}
		for(int i=1; i<=n-2; i++)
			if(s[i][j]=='0' and s[i+1][j]=='0') 
			{
				ansc=(ansc+(ll)p[i]*tmpc[i+2])%P;
				ansf=(ansf+(ll)p[i]*tmpf[i+2])%P;
			}
	}
	printf("%lld %lld\n",c*ansc,f*ansf);
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	scanf("%d%d",&T,&id);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(int i=0; i<=n+1; i++) for(int j=0; j<=m+1; j++) nxtr[i][j]=nxtc[i][j]=0;
		for(int i=0; i<=n+1; i++) p[i]=q[i]=tmpc[i]=tmpf[i]=0;
		for(int i=1; i<=n; i++)
			scanf("%s",s[i]+1);
		init(); work();
	}
	return 0;
}
