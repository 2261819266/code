#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
inline LL read(){
	LL s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=(s*10)+ch-'0';
		ch=getchar();
	}
	return s*t;
}
const LL maxn=250010;
//LL mod=1;
LL T,n,a[maxn],b[maxn],Q;
struct node{
	LL mx,l,r;
}ta[maxn<<2],tb[maxn<<2];
void build(LL x,LL l,LL r){
	ta[x].l=l; ta[x].r=r;
	tb[x].l=l; tb[x].r=r;
	if(l==r){
		ta[x].mx=a[l];
		tb[x].mx=b[l];
		return;
	}
	else{
		LL mid=(l+r)>>1;
    	build(x<<1,l,mid);
    	build(x<<1|1,mid+1,r);
      	ta[x].mx=ta[x<<1].mx;
    	if(ta[x<<1|1].mx>ta[x].mx) ta[x].mx=ta[x<<1|1].mx;
    	tb[x].mx=tb[x<<1].mx;
    	if(tb[x<<1|1].mx>tb[x].mx) tb[x].mx=tb[x<<1|1].mx;
	}
}
inline LL querya(LL x,LL L,LL R){
	LL l=ta[x].l,r=ta[x].r;
	if(L<=l&&r<=R){
		return ta[x].mx;
	}
	else{
		LL res=0,ress=0;
		LL mid=(l+r)>>1;
		if(L<=mid) res=querya(x<<1,L,R);
		if(R>mid) ress=querya(x<<1|1,L,R);
		if(ress>res) res=ress;
		return res;
	}
}
inline LL queryb(LL x,LL L,LL R){
	LL l=tb[x].l,r=tb[x].r;
	if(L<=l&&r<=R){
		return tb[x].mx;
	}
	else{
		LL res=0,ress=0;
		LL mid=(l+r)>>1;
		if(L<=mid) res=queryb(x<<1,L,R);
		if(R>mid) ress=queryb(x<<1|1,L,R);
		if(ress>res)res=ress;
		return res;
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	//for(ll i=1;i<=63;i++) mod*=2;
	//printf("%lld\n",mod);
	T=read(); n=read();
	for(LL i=1;i<=n;i++) a[i]=read();
	for(LL i=1;i<=n;i++) b[i]=read();
	build(1,1,n);
	Q=read();
	while(Q--){
		LL li=read(),ri=read();
		LL ans=0,mxa,mxb;
		for(LL p=li;p<=ri;p++){
			for(LL q=p;q<=ri;q++){
				mxa=querya(1,p,q);
				mxb=queryb(1,p,q);
				//printf("*%lld %lld: %lld %lld\n",p,q,mxa,mxb);
				ans+=mxa*mxb;
				//ans%=mod;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
