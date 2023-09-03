#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}
const int N=2e5+10,M=3e3+10;
int n;
ll a[N],b[N];
ll ma[M][M],mb[M][M];
ull out[M][M];
struct ask{
	int l,r;
}q[N];
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int id=read();n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	if(n<=3000){
	   for(int l=1;l<=n;l++){
		ma[l][l]=a[l];
		mb[l][l]=b[l];
		for(int r=l+1;r<=n;r++)
		    ma[l][r]=max(a[r],ma[l][r-1]),
		    mb[l][r]=max(b[r],mb[l][r-1]);
	}
	for(int l=1;l<=n;l++){
		out[l][l]=a[l]*b[l];
		for(int r=l+1;r<=n;r++)
		    out[l][r]=out[l][r-1]+ma[l][r]*mb[l][r];
	}
	int Q=read();
	while(Q--){
		ull ans=0;
		int l=read(),r=read();
		for(int p=l;p<=r;p++)
		    ans+=1ll*out[p][r];
		printf("%llu\n",ans);
	}
	return 0;	
	}
	int Q=read();
	int s=n,t=1;
	for(int i=1;i<=Q;i++){
		q[i].l=read(),q[i].r=read();
		s=min(s,q[i].l);
		t=max(t,q[i].r);
	}
	for(int l=s;l<=t;l++){
		ma[l][l]=a[l];
		mb[l][l]=b[l];
		for(int r=l+1;r<=t;r++)
		    ma[l][r]=max(a[r],ma[l][r-1]),
		    mb[l][r]=max(b[r],mb[l][r-1]);
	}
	for(int l=s;l<=t;l++){
		out[l][l]=a[l]*b[l];
		for(int r=l+1;r<=t;r++)
		    out[l][r]=out[l][r-1]+ma[l][r]*mb[l][r];
	}
	for(int i=1;i<=Q;i++){
		ull ans=0;
		for(int p=q[i].l;p<=q[i].r;p++)
		    ans+=1ll*out[p][q[i].r];
		printf("%llu\n",ans);
	}
	return 0;
}
