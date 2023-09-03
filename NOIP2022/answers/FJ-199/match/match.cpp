#include<bits/stdc++.h>
using namespace std;
int T,n,m,Q,ll,rr;
long long ans;
int a[250010],b[250010];
int k1[1000010],k2[1000010];
long long qiu=pow(2,32);
void build(int w[],int l,int r,int idx,int o[]) {
	if(l==r) {
		o[idx]=w[l];
	} else {
		int mid=(r+l)/2;
		build(w,l,mid,2*idx,o);
		build(w,mid+1,r,2*idx+1,o);
		o[idx]=max(o[idx*2],o[idx*2+1]);
	}
}
int quary(int w[],int lp,int rq,int l,int r,int idx) {
	int ar=0,al=0;
	if(l>=lp&&r<=rq) return w[idx];
	int mid=(r+l)/2;
	if(lp<=mid)  ar=quary(w,lp,rq,l,mid,idx*2);
	if(rq>=mid+1) al=quary(w,lp,rq,mid+1,r,idx*2+1);
	return max(ar,al);
}
int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(int i=1; i<=n; i++)
		scanf("%d",&b[i]);
	build(a,1,n,1,k1);
	build(b,1,n,1,k2);
	scanf("%d",&Q);
	while(Q--) {
		ans=0;
		scanf("%d%d",&ll,&rr);
		for(int p=ll; p<=rr; p++) {
			for(int q=p; q<=rr; q++) {
				ans+=(quary(k1,p,q,1,n,1)*quary(k2,p,q,1,n,1))%qiu;
			}
		}
		printf("%d",ans);
	}
	return 0;
}
