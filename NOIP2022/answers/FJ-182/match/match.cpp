#include<bits/stdc++.h>
#define F(i,x,n) for(int i=x;i<=n;++i)
#define _F(i,x,n) for(int i=x;i>=n;--i)
#define ll long long
#define ull unsgined long long
#define lson x<<1
#define rson x<<1|1
#define lowbit(x) x&-x
#define int long long
using namespace std;

inline int read(){
	int s=0;char c=getchar();bool flag=0;
	while(!isdigit(c))flag|=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return flag?-s:s;
}

const int N=3e5+5;//数组不要开小，记得检查。 

int a[N],b[N],mx[2][3005][3005],mod;
int T,n,Q;

signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	F(i,1,n)a[i]=read();
	F(i,1,n)b[i]=read();mod=1;
	F(i,1,64)mod*=2;
	F(l,1,n){
		mx[0][l][l]=a[l];
		F(r,l+1,n){
			mx[0][l][r]=max(mx[0][l][r-1],a[r]);
		}
	}
	F(l,1,n){
		mx[1][l][l]=b[l];
		F(r,l+1,n){
			mx[1][l][r]=max(mx[1][l][r-1],b[r]);
		}
	}
	Q=read();
	while(Q--){
		int l=read(),r=read();
		int ans=0;
		F(p,l,r)F(q,p,r){
			ans=(ans+mx[0][p][q]*mx[1][p][q]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
