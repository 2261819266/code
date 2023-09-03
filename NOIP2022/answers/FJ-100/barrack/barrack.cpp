#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll read()
{
	char c=getchar(); ll res=0, f=1;
	while(!isdigit(c)) {if(c=='-') f=-1; c=getchar();}
	while(isdigit(c)) {res=(res<<3)+(res<<1)+(c^48); c=getchar();}
	return res*f;
}
void write(ll x)
{
	if(x<0) x=-x, putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

const int N=5e5+1,mod=1e9+7;

int n,m;
vector<int> E[N];

ll qpow(ll x,ll y) {ll res=1; for(;y;y>>=1ll,x=(x*x)%mod) if(y&1ll) res=(res*x)%mod; return res;}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(), m=read();
	for(int i=1,x,y;i<=m;++i)
	{
		x=read(), y=read();
		E[x].push_back(y);
		E[y].push_back(x);
	}
	ll ans=0;
	for(int l=1;l<n;++l)
	{
		ans = (ans + (n-l)*qpow(2,n-2)%mod) %mod;
	}
	ans = (ans + n * qpow(2,m)%mod) %mod;
	write(ans);
}
