#include<map>
#include<set>
#include<ctime>
#include<cmath>
#include<stack>
#include<queue>
#include<random>
#include<bitset>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#define I inline ll
#define ll long long 
using namespace std;
#define cht 998244353
#define her1 20090115//I love her
#define IV inline void
#define ull unsigned long long
#define F(i,j,n)for(int i=j;i<=n;i++)
#define D(i,j,n)for(int i=j;i>=n;i--)
#define E(i,now)for(int i=first[now];i;i=e[i].nxt)
#define FL(i,j,n)for(ll i=j;i<=n;i++)
#define DL(i,j,n)for(ll i=j;i>=n;i--)
#define EL(i,now)for(ll i=first[now];i;i=e[i].nxt)
#define mem(x,val)memset(x,val,sizeof x)
ll read(){
	ll ans=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')ans=ans*10+c-'0',c=getchar();
	return ans*f;
}
mt19937 rnd(her1);
const int maxn = 2.5e5+5;
ll n;ull a[maxn],b[maxn];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read();n=read();
	F(i,1,n)a[i]=read();
	F(i,1,n)b[i]=read();
	ll Q=read();while(Q--){
		ll l=read(),r=read();ull ans=0,mx1=0,mx2=0;
		F(p,l,r){
			mx1=mx2=0;
			F(q,p,r)mx1=max(mx1,a[q]),mx2=max(mx2,b[q]),ans+=mx1*mx2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
