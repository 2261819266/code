#include<bits/stdc++.h>
#define f(i,a,b,c) for(int i=a;i<=b;i+=c)
#define GC c=getchar()
#define IG isdigit(c)
using namespace std;
const int N=3e5+10;
template <class T=int>T qread(T x=0,char GC,bool f=1)
{
	for(;!IG;GC) f=c!='-';
	for(;IG;GC) x=x*10+(c^48);
	return f?x:-x;
}
int a[N],b[N];
int n,m,T,Q,l,r;
long long ans=0;
long long maxx(int al,int bl)
{
	int g=0,s=0;
	long long qwq=0;
	f(i,al,bl,1) g=max(g,a[i]);
	f(i,al,bl,1) s=max(s,b[i]);
	qwq=g*s;
	return qwq;
}
signed main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=qread(),n=qread();
	f(i,1,n,1) 
	{
		a[i]=qread();
	}
	f(i,1,n,1) 
	{
		b[i]=qread();
	}
	Q=qread();
	while(Q--)
	{
		ans=0;
		l=qread(),r=qread();
		f(i,l,r,1)
		{
			f(j,i,r,1)
			{
				ans+=maxx(i,j);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

