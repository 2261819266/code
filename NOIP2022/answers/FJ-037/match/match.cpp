#include<cstdio>
#include<cmath>
#include<algorithm>
const int H=100000010;
char G[H],*_=G;
int read(){
	int x=0;
	while(*_<'0'||'9'<*_)_++;
	while('0'<=*_&&*_<='9')x=x*10+(*_++&15);
	return x;
}
int T,n; 
const int N=250050;
int size,Q;
unsigned long long a[N],b[N],sum1[N],sum2[N],Ans[N];
int st[N],L1[N],L2[N],B[N];
struct node{
	int l,r,id;
	bool operator<(const node &A)const {
		if(b[l]!=b[A.l])return b[l]<b[A.l];
		if(b[l]&1)return r>A.r;else return r<A.r;
	}
}A[N];
unsigned long long calc1(int x,int r){
	unsigned long long ans=0;
	while(L1[x]<=r)ans+=(L1[x]-x)*a[x],x=L1[x];
	ans+=(r-x+1)*a[x];
	return ans;
}
unsigned long long calc2(int x,int r){
	unsigned long long ans=0;
	while(L2[x]<=r)ans+=(L2[x]-x)*b[x],x=L2[x];
	ans+=(r-x+1)*b[x];
	return ans;
}
int main(){
	freopen("match.in","r",stdin),freopen("match.out","w",stdout);
	fread(G,1,H,stdin),T=read(),n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sum1[i]=sum1[i-1]+a[i];
	for(int i=1;i<=n;i++)b[i]=read(),sum2[i]=sum2[i-1]+a[i];
	Q=read(),size=sqrt(Q);
	for(int i=1;i<=n;i++)B[i]=i/size;
	st[0]=n+1,a[n+1]=b[n+1]=n+1;
	for(int i=n,tp=0;i>=1;i--){
		while(tp&&a[i]>=a[st[tp]])tp--;
		L1[i]=st[tp],st[++tp]=i;
	}
	for(int i=n,tp=0;i>=1;i--){
		while(tp&&b[i]>=b[st[tp]])tp--;
		L2[i]=st[tp],st[++tp]=i;
	}
	for(int i=1;i<=Q;i++)A[i].l=read(),A[i].r=read(),A[i].id=i;
	std::sort(a+1,a+Q+1);
	unsigned long long ans=0;
	for(int i=1,l=1,r=0;i<=Q;i++){
		while(r<A[i].r)r++,ans+=b[r]*calc1(l,r);
		while(l>A[i].l)l--,ans+=a[l]*calc2(l,r);
		while(r>A[i].r)ans-=b[r]*calc1(l,r),r--;
		while(l>A[i].l)ans-=a[l]*calc2(l,r),l++;
		Ans[A[i].id]=ans;
	}
	for(int i=1;i<=Q;i++)printf("%llu\n",Ans[i]);
	return 0;
}
