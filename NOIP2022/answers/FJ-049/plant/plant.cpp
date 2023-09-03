#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <random>
#include <bitset>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#define rep(i,j,k) for(int i=j;i<=(k);++i)
#define drp(i,j,k) for(int i=j;i>=(k);--i)
#define isdigit(ch) (ch>=48&&ch<=57)
#define mp std::make_pair
#define mod 998244353
#define MAXN 1005
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
const double eps=1e-6;
const double pi=acos(-1);
const int dx[8]={1,-1,0,0,1,1,-1,-1};
const int dy[8]={0,0,1,-1,1,-1,1,-1};
inline int read(){
	int x=0;
	char ch=getchar();
	bool f=false;
	while(!isdigit(ch)) f|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
inline ll readll(){
	ll x=0;
	char ch=getchar();
	bool f=false;
	while(!isdigit(ch)) f|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
template <typename tp> inline tp min(tp a,tp b){return a<b?a:b;}
template <typename tp> inline tp max(tp a,tp b){return a>b?a:b;}
template <typename tp> inline bool chkmin(tp &a,tp b){return a>b&&(a=b,true);}
template <typename tp> inline bool chkmax(tp &a,tp b){return a<b&&(a=b,true);}
int task,n,m,len[MAXN][MAXN];
char s[MAXN][MAXN];
ll f[MAXN][MAXN][2][2];
inline void init(){
	memset(s,0,sizeof(s));
	memset(f,0,sizeof(f));
	memset(len,0,sizeof(len));
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	task=read(),read();
	while(task--){
		n=read(),m=read(),read(),read(),init();
		rep(i,1,n) scanf("%s",s[i]+1);
		rep(i,1,n) drp(j,m,1) if(s[i][j]=='0') len[i][j]=len[i][j+1]+1;
		rep(i,1,n) rep(j,1,m) if(s[i][j]=='0'){
			f[i][j][0][0]=max(len[i][j]-1,0);
			f[i][j][0][1]=(f[i-1][j][0][0]+f[i-1][j][0][1])%mod;
			f[i][j][1][0]=f[i-1][j][0][1]*max(len[i][j]-1,0)%mod;
			f[i][j][1][1]=(f[i-1][j][1][0]+f[i-1][j][1][1])%mod;
		}
		pll ans=mp(0,0);
		rep(i,1,n) rep(j,1,m){
			(ans.first+=f[i][j][1][0])%=mod;
			(ans.second+=f[i][j][1][1])%=mod;
		}
		printf("%lld %lld\n",ans.first,ans.second);
	}
}
