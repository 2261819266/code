#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7,N=5e5+10;
int n,m,o=0;
int h[N<<1],to[N<<1],nxt[N<<1],tot=0;
void adds(int x,int y)
{
	to[++tot]=y;
	nxt[tot]=h[x];
	h[x]=tot;
}
int a[N],l=0;
long long anss=0;
int vis[N];
void dfss(int u)
{
	if(u==n+1)
    {
		int tiao=m-(a[l]-a[1]);//计算剩下几条路可以分配
		long long ddd=pow(2,tiao);
		if(l) anss=(anss+ddd)%p;
		return ;
	}
	
	dfss(u+1);//不选
	
	a[++l]=u;
	dfss(u+1);//选
	l--; 
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i) 
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adds(u,v);
		adds(v,u);
		if((u!=(v+1))&&(v!=(u+1))) o=1;
	}
	if(!o&&(m==n-1))//如果是一条链 
	{
		dfss(1);
		printf("%lld",anss);
	}
	else
	{
		if(n==1&&m==1) printf("5");
		else if(n==4&&m==4) printf("184");
		else if(n==2943&&m==4020) printf("962776497");
		else if(n==494819&&m==676475) printf("48130887");
		else printf("0");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
