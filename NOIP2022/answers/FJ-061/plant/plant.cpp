//expect /hs /bs expect
#include<bits/stdc++.h>
#define int long long
#define rep(i,j,k) for(int i=(j),_i=(k);i<=_i;++i)
#define drp(i,j,k) for(int i=(j),_i=(k);i>=_i;--i)
using namespace std;
inline int read() {
	int x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//-----------------------------------------------//
const int N=1e3+5,mod=998244353;
int n,m,c[N][N],f[N][N];
int d[N][N],r[N][N],ac,af;
int exPect_C,exPect_F;
char a[N][N];


void init() {
	#define cl(x) memset(x,0,sizeof(x))
	cl(c);cl(f);cl(r);cl(d);
	ac=af=0;
}

signed main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T=read(),id=read();
	while(T--) {
		init();
		n=read(),m=read();
		exPect_C=read();
		exPect_F=read();
		rep(i,1,n) cin>>(a[i]+1);
		drp(j,m,1) rep(i,1,n) 
		  r[i][j]=(a[i][j]=='0'?r[i][j+1]+1:0);
		drp(i,n,1) rep(j,1,m) 
		  d[i][j]=(a[i][j]=='0'?d[i+1][j]+1:0);
		rep(j,1,m) {
			int pre=0;
			rep(i,1,n) {
				if(a[i][j]=='1') {pre=0;continue;}
				ac=(ac+(r[i][j]-1)*pre)%mod;
				af=(af+(r[i][j]-1)*(d[i][j]-1)*pre)%mod;
				if(a[i-1][j]=='0') pre+=r[i-1][j]-1;
			}
		}
		printf("%lld %lld\n",ac*exPect_C,af*exPect_F);
	}
	return 0;
}
