#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n,Q;
inline ll Read()
{
	ll x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') { x=x*10+ch-48;ch=getchar(); }
	return x;
}
inline int Read1()
{
	int x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0') ch=getchar();
	while(ch>='0'&&ch<='9') { x=x*10+ch-48;ch=getchar(); }
	return x;
}
struct Tree
{
	int maxid;
	ll maxn;
}ta[600500],tb[600500];
inline Tree maxt(Tree a,Tree b)
{
	if(a.maxn>=b.maxn) return a;
	else return b;
}
void builda(int i,int l,int r)
{
	if(l==r)
	{
		ta[i].maxid=l,ta[i].maxn=Read();
		return;
	}
	int mid=(l+r)>>1;
	builda(i<<1,l,mid);
	builda(i<<1|1,mid+1,r);
	ta[i]=maxt(ta[i<<1],ta[i<<1|1]);
	return;
}
void buildb(int i,int l,int r)
{
	if(l==r)
	{
		tb[i].maxid=l,tb[i].maxn=Read();
		return;
	}
	int mid=(l+r)>>1;
	buildb(i<<1,l,mid);
	buildb(i<<1|1,mid+1,r);
	tb[i]=maxt(tb[i<<1],tb[i<<1|1]);
	return;
}
ll querya(int i,int l,int r,int x,int y)
{
	if(r<x||l>y) return 0;
	if(ta[i].maxid>=x&&ta[i].maxid<=y) return ta[i].maxn;
	int mid=(l+r)>>1;
	if(x>mid) return querya(i<<1|1,mid+1,r,x,y);
	else if(y<=mid) return querya(i<<1,l,mid,x,y);
	else return max(querya(i<<1,l,mid,x,mid),querya(i<<1|1,mid+1,r,mid+1,y));
}
ll queryb(int i,int l,int r,int x,int y)
{
	if(r<x||l>y) return 0;
	if(tb[i].maxid>=x&&tb[i].maxid<=y) return tb[i].maxn;
	int mid=(l+r)>>1;
	if(x>mid) return queryb(i<<1|1,mid+1,r,x,y);
	else if(y<=mid) return queryb(i<<1,l,mid,x,y);
	else return max(queryb(i<<1,l,mid,x,mid),queryb(i<<1|1,mid+1,r,mid+1,y));
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
    int T=Read1();
    n=Read1();
    builda(1,1,n);
    buildb(1,1,n);
    Q=Read1();
    int l,r;
    ll ans=0;
    while(Q--)
    {
    	l=Read1(),r=Read1();
    	ans=0;
    	for(int p=l;p<=r;p++)
    	  for(int q=r;q>=p;q--)
    	    ans+=(querya(1,1,n,p,q)*queryb(1,1,n,p,q));
    	printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
