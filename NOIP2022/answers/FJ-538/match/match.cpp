#include<bits/stdc++.h>
using namespace std;
const unsigned long long N=5000;
unsigned long long f[N][N];
unsigned long long T,n,a[N],b[N],q;
struct Node{
	unsigned long long l,r,mxa,mxb;
};
Node s[N*4];
void build(unsigned long long p,unsigned long long l,unsigned long long r){
	s[p].l=l,s[p].r=r;
	if(l==r)	{s[p].mxa=a[l],s[p].mxb=b[l];return;}
	unsigned long long mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	s[p].mxa=max(s[p*2].mxa,s[p*2+1].mxa);
	s[p].mxb=max(s[p*2].mxb,s[p*2+1].mxb);
}
unsigned long long ask(unsigned long long p,unsigned long long l,unsigned long long r,unsigned long long op){
	if(s[p].l>=l&&s[p].r<=r)	return (op==1?s[p].mxa:s[p].mxb);
	unsigned long long ret=0,mid=(s[p].l+s[p].r)/2;
	if(l<=mid)	ret=max(ret,ask(p*2,l,r,op));
	if(r>mid)	ret=max(ret,ask(p*2+1,l,r,op));
	return ret;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>T>>n;
	for(unsigned long long i=1;i<=n;i++)	scanf("%lld",&a[i]);
	for(unsigned long long i=1;i<=n;i++)	scanf("%lld",&b[i]);
	build(1,1,n);
	for(unsigned long long i=1;i<=n;i++)	f[i][i]=ask(1,i,i,1)*ask(1,i,i,2);
	for(unsigned long long i=1;i<n;i++)	f[i][i+1]=ask(1,i,i+1,1)*ask(1,i,i+1,2)+f[i][i]+f[i+1][i+1];
	for(unsigned long long len=2;len<n;len++){
		for(unsigned long long l=1,r=1+len;r<=n;l++,r++){
			f[l][r]=f[l][r-1]+f[l+1][r]-f[l+1][r-1]+ask(1,l,r,1)*ask(1,l,r,2);
		}
	}
	cin>>q;
	while(q--){
		unsigned long long l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",f[l][r]);
	}
	return 0;
}
