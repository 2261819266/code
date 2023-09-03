#include<bits/stdc++.h>
using namespace std;
#define maxn 3001
#define inf 99999999999999999
#define ll unsigned long long
#define mod 998244353
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-48;ch=getchar();}
	return x*f;
}
ll T,n,a[maxn],b[maxn],st1[maxn][51],st2[maxn][51],lgg[maxn];
ll Q,l,r,nowans=0,mi[maxn];
ll query(ll x,ll y,ll kin){
	ll nowlg=lgg[y-x+1];
	if(kin==1) return max(st1[x][nowlg],st1[y-mi[nowlg]+1][nowlg]);
	else return max(st2[x][nowlg],st2[y-mi[nowlg]+1][nowlg]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(ll i=1;i<=n;i++) a[i]=read(),st1[i][0]=a[i];
	for(ll i=1;i<=n;i++) b[i]=read(),st2[i][0]=b[i];
	lgg[1]=0,mi[0]=1;
	for(ll i=1;i<=25;i++) mi[i]=mi[i-1]*2;
	for(ll i=2;i<=n;i++){
		if(2*mi[lgg[i-1]]>=i) lgg[i]=lgg[i-1];
		else lgg[i]=lgg[i-1]+1;
	}
	for(ll i=1;i<=25;i++){
		for(ll j=1;(j+mi[i]-1)<=n;j++){
			st1[j][i]=max(st1[j][i-1],st1[j+mi[i-1]][i-1]);
			st2[j][i]=max(st2[j][i-1],st2[j+mi[i-1]][i-1]);
		}
	}
	Q=read();
	while(Q--){
		nowans=0;
		l=read(),r=read();
		for(ll i=l;i<=r;i++){
			for(ll j=i;j<=r;j++){
				nowans+=query(i,j,1)*query(i,j,2);
			}
		}
		printf("%lld\n",nowans);
	}
	return 0;
}

