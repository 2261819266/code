#include<bits/stdc++.h>
using namespace std;
template<typename T>void rd(T&x){
	x=0;int f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-48;c=getchar();}
	x*=f;
}
int getc(){
	int c;
	while(isspace(c=getchar()));
	return c;
}
typedef long long ll;
const ll N=1010,M=1010,mod=998244353;
inline void inc(ll&x,ll y){x=(x+y)%mod;}
ll t,id;
ll n,m,c,f,vc,vf;
ll l[N][M],p[N][M];
bool a[N][M];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	rd(t);rd(id);
	while(t--){
		memset(l,-1,sizeof l);
		memset(p,-1,sizeof p);
		rd(n);rd(m);rd(c);rd(f);vc=vf=0;
		for(ll i=1;i<=n;++i)a[i][0]=a[i][m+1]=1;
		for(ll j=1;j<=m;++j)a[0][j]=a[n+1][j]=1;
		for(ll i=1;i<=n;++i){
			for(ll j=1;j<=m;++j)a[i][j]=getc()&1;
			for(ll j=m;j;--j)if(!a[i][j])l[i][j]=l[i][j+1]+1;
		}
		for(ll j=1;j<=m;++j){
			for(ll i=n;i;--i)if(!a[i][j])p[i][j]=a[i][j]?0:p[i+1][j]+1;
			for(ll i=1,s=0;i<=n;++i){
				if(a[i][j]){s=0;continue;}
				if(c)inc(vc,l[i][j]*s%mod);
				if(f)inc(vf,l[i][j]*s%mod*p[i][j]);
				if(!a[i-1][j])inc(s,l[i-1][j]);
			}
		}
		printf("%d %d\n",vc,vf);
	}
	return 0;
}

