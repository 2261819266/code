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
#define MAXN 2000005
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
int n,m,k,a[MAXN],stk[MAXN][2];
inline void init(){
	rep(i,1,n) stk[i][0]=stk[i][1]=0;
}
inline void check(int val){
	int pos=0;
	rep(i,1,n-1) if(stk[i][0]==val) pos=i;
	if(pos){
		printf("1 %d\n",n);
		printf("2 %d %d\n",pos,n);
		stk[pos][0]=stk[pos][1],stk[pos][1]=0;
		return;
	}
	rep(i,1,n-1) if(stk[i][1]==val) pos=i;
	if(pos){
		printf("1 %d\n",pos);
		stk[pos][1]=0;
		return;
	}
    rep(i,1,n){
		if(stk[i][1]) continue;
		printf("1 %d\n",i);
		if(!stk[i][0]) stk[i][0]=val;
		else stk[i][1]=val;
		return;
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	drp(task,read(),1){
		n=read(),m=read(),k=read(),init();
		rep(i,1,m) a[i]=read();
		rep(i,1,m) check(a[i]);
	}
}
