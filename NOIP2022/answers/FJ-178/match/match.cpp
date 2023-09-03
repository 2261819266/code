#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=3e5+5;
ll T,n,l,r,x,y,q,a[N],b[N],log_2[N],fa[N][20],fb[N][20];
void init(){
	for(int i=1;i<=n;i++){
		fa[i][0]=a[i];fb[i][0]=b[i];
	}
	for(int i=2;i<=n;i++) log_2[i]=log_2[i>>1]+1;
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<j)-1<=n;i++){
			fa[i][j]=max(fa[i][j-1],fa[i+(1<<(j-1))][j-1]);
			fb[i][j]=max(fb[i][j-1],fb[i+(1<<(j-1))][j-1]);
		}
			
}
ll query_a(int L,int R){
	int k=log_2[R-L+1];
	return max(fa[L][k],fa[R-(1<<k)-1][k]);
}
ll query_b(int L,int R){
	int k=log_2[R-L+1];
	return max(fb[L][k],fb[R-(1<<k)-1][k]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%lld%lld",&T,&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]);
	init();
	scanf("%lld",&q);
	for(int i=1;i<=q;i++){
		ll ans=0;
		scanf("%d%d",&l,&r);
		for(int p1=l;p1<=r;p1++)     
			for(int p2=p1;p2<=r;p2++)
				ans+=query_a(p1,p2)*query_b(p1,p2);
		printf("%lld\n",ans);
	}
	return 0;  
}
