#include<bits/stdc++.h>
#define ull unsigned long long 
using namespace std;
int rd(){char c;bool f(1);while(!isdigit(c=getchar()))f=c!='-';int x(c-48);while(isdigit(c=getchar()))x=x*10+(c-48);return f?x:-x;}
const int N(2.5e5+5);
int T,n,Q;
ull a[N+5],b[N+5];
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=rd(),n=rd();
	for(int i(1);i<=n;++i)a[i]=rd();
	for(int i(1);i<=n;++i)b[i]=rd();
	for(Q=rd();Q--;)
	{
		int l(rd()),r(rd());
		ull res(0);
		for(int tl(l);tl<=r;++tl)
		{
			ull mxa(0),mxb(0);
			for(int tr(tl);tr<=r;++tr)
			{
				mxa=max(mxa,a[tr]);
				mxb=max(mxb,b[tr]);
				res+=mxa*mxb;
			}
		}
		printf("%llu\n",res);
	}
	return 0;
}
