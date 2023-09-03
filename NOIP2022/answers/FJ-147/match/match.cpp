#include<stdio.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
const int N=2.5e5+5;
int T,n,q,a[N],b[N],ma[N],mb[N];
ull ans,sa[N],sb[N],sab[N];
void solve(int l,int r){
	if(l==r){
		ans+=1ull*a[l]*b[l];
		return;
	}
	int mid=l+r>>1;
	ma[mid]=a[mid],ma[mid+1]=a[mid+1];
	mb[mid]=b[mid],mb[mid+1]=b[mid+1];
	for(int i=mid-1;i>=l;--i)ma[i]=max(ma[i+1],a[i]),mb[i]=max(mb[i+1],b[i]);
	for(int i=mid+2;i<=r;++i)ma[i]=max(ma[i-1],a[i]),mb[i]=max(mb[i-1],b[i]);
	sa[r+1]=sb[r+1]=sab[r+1]=0;
	for(int i=r;i>mid;--i)sa[i]=sa[i+1]+ma[i],sb[i]=sb[i+1]+mb[i],sab[i]=sab[i+1]+1ull*ma[i]*mb[i];
	for(int i=mid,pa=mid+1,pb=mid+1;i>=l;--i){
		while(pa<=r&&ma[pa]<ma[i])++pa;
		while(pb<=r&&mb[pb]<mb[i])++pb;
	//	printf("%d %d\n",pa,pb);
		if(pa>pb){
			ans+=1ull*(pb-mid-1)*ma[i]*mb[i];
			ans+=1ull*ma[i]*(sb[pb]-sb[pa]);
			ans+=sab[pa];
		}else{
			ans+=1ull*(pa-mid-1)*ma[i]*mb[i];
			ans+=1ull*mb[i]*(sa[pa]-sa[pb]);
			ans+=sab[pb];
		}
	}
	solve(l,mid),solve(mid+1,r);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;++i){
		scanf("%d%d",&l,&r);
		ans=0;
		solve(l,r);
		printf("%llu\n",ans);
	}
	return 0;
}
