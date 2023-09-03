#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
int T,n,q;
ULL ans;
int a[250002],b[250002],A[250002],B[250002];
ULL sumA[250002],sumB[250002],sumAB[250002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;
}
inline void solve(int l,int r)
{
	//printf("solve %d %d\n",l,r);
	if(l==r)
	{
		ans+=(ULL)a[l]*b[l];
		return ;
	}
	int mid=((l+r)>>1);
	solve(l,mid),solve(mid+1,r);
	A[mid]=a[mid];for(int i=mid-1;i>=l;--i)A[i]=max(a[i],A[i+1]);
	A[mid+1]=a[mid+1];for(int i=mid+1;i<=r;++i)A[i]=max(a[i],A[i-1]);
	B[mid]=b[mid];for(int i=mid-1;i>=l;--i)B[i]=max(b[i],B[i+1]);
	B[mid+1]=b[mid+1];for(int i=mid+1;i<=r;++i)B[i]=max(b[i],B[i-1]);
	sumA[mid]=sumB[mid]=sumAB[mid]=0;for(int i=mid+1;i<=r;++i)sumA[i]=sumA[i-1]+A[i],sumB[i]=sumB[i-1]+B[i],sumAB[i]=sumAB[i-1]+(ULL)A[i]*B[i];
	
	//mid+1~iA/iB left is bigger
	
	//printf("l:%d mid:%d r:%d ans:%llu\n",l,mid,r,ans);
	for(int i=l,iA=r,iB=r;i<=mid;++i)
	{
		for(;iA>mid && A[i]<A[iA];--iA);
		for(;iB>mid && B[i]<B[iB];--iB);
		//printf(" i:%d iA:%d iB:%d\n",i,iA,iB);
		ans+=(ULL)(min(iA,iB)-mid)*A[i]*B[i];
		//printf("  1. ans -> %llu\n",ans);
		if(iA<=iB)ans+=(ULL)B[i]*(sumA[iB]-sumA[iA]);
		else ans+=(ULL)A[i]*(sumB[iA]-sumB[iB]);
		//printf("  2. ans -> %llu\n",ans);
		ans+=sumAB[r]-sumAB[max(iA,iB)];
		//printf("  3. ans -> %llu\n",ans);
	}
}
int main()
{
	//system("fc match.out match3.ans");return 0;
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	read(T),read(n);
	for(int i=1;i<=n;++i)read(a[i]);
	for(int i=1;i<=n;++i)read(b[i]);
	read(q);
	for(int l,r;q--;)
	{
		read(l),read(r),ans=0;
		solve(l,r);
		printf("%llu\n",ans);
	}
	
	return 0;
}
