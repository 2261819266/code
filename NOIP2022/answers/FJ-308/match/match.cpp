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
const int maxn=3012;
using ll = long long;
int n,q,l,r,t;
ll ans,mxn1,mxn2,nl[maxn],ml[maxn];
int main()
{
	finfout(match);
	t=in();n=in();
	fru(i,1,n)nl[i]=in();
	fru(i,1,n)ml[i]=in();
	q=in();
	fru(i,1,q)
	{
		l=in();r=in();
		ans=0;
		fru(k,l,r)fru(o,k,r)
		{
			mxn1=mxn2=0;	
			fru(t,k,o)
			{
				mxn1=max(mxn1,nl[t]);
				mxn2=max(mxn2,ml[t]);
			}	
		ans+=mxn1*mxn2;
		}
	out(ans);pc('\n');
	}	
	return 0;
}
/*
input:
0 2
2 1
1 2
1
1 2
output:
8
*/
