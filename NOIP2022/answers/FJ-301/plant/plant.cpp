#include<map>
#include<set>
#include<ctime>
#include<cmath>
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
const int maxn = 1e3+5;
IV cadd(ll&x,ll val){x=(x+val)%cht;}char s[maxn][maxn];
ll n,m,R[maxn][maxn],c,vc,f,vf,D[maxn][maxn],sc[maxn][maxn],sf[maxn][maxn];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	ll T=read();read();
	while(T--){
		n=read();m=read();c=read();f=read();vc=0;vf=0;
		mem(sc,0);mem(sf,0);mem(R,0);mem(D,0);F(i,1,n)scanf("%s",s[i]+1);
		F(i,1,n)D(j,m,1)if(s[i][j]=='0')R[i][j]=R[i][j+1]+1;else R[i][j]=0;
		D(i,n,1)F(j,1,m)if(s[i][j]=='0')D[i][j]=D[i+1][j]+1;else D[i][j]=0;
		F(i,1,n)F(j,1,m)sc[i][j]=max(0ll,R[i][j]-1),sf[i][j]=sc[i][j]*max(0ll,D[i][j]-1);
//		F(i,1,n){
//			F(j,1,m)cout<<sc[i][j]<<' ';
//			puts("");
//		}
//		F(i,1,n){
//			F(j,1,m)cout<<sf[i][j]<<' ';
//			puts("");
//		}
		F(i,1,n)F(j,1,m)cadd(sc[i][j],sc[i-1][j]),cadd(sf[i][j],sf[i-1][j]);
		F(l,1,n)F(j,1,m)if(s[l][j]=='0'){
			ll r=l+D[l][j]-1;//cout<<l+2<<' '<<r<<' '<<j<<endl;
			if(l+2<=r)cadd(vc,(sc[r][j]-sc[l+1][j])*max(0ll,R[l][j]-1));
			if(l+2<=r)cadd(vf,(sf[r][j]-sf[l+1][j])*max(0ll,R[l][j]-1));
		}vc+=cht;vf+=cht;vc%=cht;vf%=cht;
		printf("%lld %lld\n",vc*c%cht,vf*f%cht);
	}
	return 0;
}
