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
#define mod 1000000007
#define MAXN 3005
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
int n,m,a[MAXN],b[MAXN];
ull sum[MAXN][MAXN];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(),n=read();
	rep(i,1,n) a[i]=read();
	rep(i,1,n) b[i]=read();
	rep(i,1,n){
		int vx=0,vy=0;
		rep(j,i,n){
			chkmax(vx,a[j]);
			chkmax(vy,b[j]);
			sum[i][j]=(ull)vx*vy;
		}
	}
	rep(i,1,n) rep(j,1,n) sum[i][j]=sum[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	m=read();
	while(m--){
		int l=read(),r=read();
		printf("%llu\n",sum[r][r]-sum[r][l-1]-sum[l-1][r]+sum[l-1][l-1]);
	}
}
