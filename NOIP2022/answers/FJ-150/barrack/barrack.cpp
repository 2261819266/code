#include<bits/stdc++.h>
#define Re register
using namespace std;

const int N=500005,M=1000005,mod=1000000007;

bool A;

int n,m;

struct Node{
	int ver,nxt;
}e[M<<1];
int cnt,hd[N];

inline void add(int u,int v)
{
	cnt++;
	e[cnt].ver=v;
	e[cnt].nxt=hd[u];
	hd[u]=cnt;
}

inline int ksm(int a,int b)
{
	int res=1ll;
	while(b)
	{
		if(b&1) res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n==1){puts("1");return 0;}
	for(Re int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
		if(abs(u-v)>1) A=1;
	}
	if(m==n-1)
	{
		if(!A)
		{
			if(n==2){puts("5");return 0;}
			printf("%lld\n",(1ll*ksm(2,n-3)*(1ll*n*(n-1)%mod)%mod+1ll*ksm(2,n-1)*n%mod)%mod);
			return 0;
		}
	}
	else printf("%lld\n",(1ll*n*ksm(2,n))%mod);
	return 0;
}
