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
using ll = long long;
const ll mod= 1000000007;
int n,m,a[112],b[112],fa[112];
ll tp2[700012],ans;
bool bl[112],ml[112];
inline int findfa(int x)
{
	while(x^fa[x])x=fa[x]=fa[fa[x]];
	return x;
}
void dfs2(int dc);
inline bool pd(void);
void dfs(int dc)
{
//	cout<<dc<<endl;
//	fru(i,1,n)
//	{
//		cout<<bl[i]<<' ';
//	}cout<<endl;
//	getchar();
	if(dc==n+1)
	{
	bool bbl=false;
	fru(i,1,n)bbl|=bl[i];
	if(!bbl)return ;
		dfs2(1);
		return ;
	}
	bl[dc]=true;
	dfs(dc+1);
	bl[dc]=false;
	dfs(dc+1);
}
void dfs2(int dc)
{
	if(dc==m+1)
	{
		if(pd())
		{
		ans++;	
		}
		return ;
	}
	ml[dc]=true;
	dfs2(dc+1);
	ml[dc]=false;
	dfs2(dc+1);
}
int xx,yy;
inline bool pd(void)
{
	fru(kkk,1,m)if(!ml[kkk])
	{
	fru(i,1,n)fa[i]=i;
	fru(i,1,m)if(i^kkk)
	{
		xx=findfa(a[i]);
		yy=findfa(b[i]);
		fa[xx]=yy;
	}
	int dc=-1;
	fru(i,1,n)
	if(bl[i])
	{
	if(dc==-1)
	dc=findfa(i);
	else {
	if(dc^findfa(i))return false;	}
	}
	}
	return true;
}
int main()
{
	finfout(barrack);
	n=in();m=in();
	if(m==(n-1))
	{
		tp2[0]=1;
		fru(i,1,n)(tp2[i]=tp2[i-1]<<1)%=mod;
		fru(i,1,n-1)
		(ans+=((n-i)*tp2[n-i-1]%mod)*tp2[i-1]%mod)%=mod;
		(ans+=n*tp2[n-1]%mod)%=mod;
		out(ans);
		return 0;
	}
	fru(i,1,m)
	a[i]=in(),b[i]=in();
	dfs(1);
	out(ans);
	return 0;
}
/*
input:
4 4
1 2
2 3
3 1
1 4
output:
184
*/
