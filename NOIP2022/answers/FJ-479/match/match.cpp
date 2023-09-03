#include<bits/stdc++.h>
//#define int long long
#define int unsigned long long
#define For(w,x,y,z) for(int w=(x);w<=(y);w+=(z))
#define foR(w,x,y,z) for(int w=(x);w>=(y);w-=(z))
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c-48);c=getchar();}
	return x*f;
}
inline void write(int x){
	if(x<0) {putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
inline void fl(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
}
const int N=3e5+10;
int Q,T,n,a[N],b[N],suma[N],sumb[N];
struct node{
	int tree[300010];
	void build(int l,int r,int k){
		if(l==r){
			tree[k]=a[l];
			return;
		}
		int mid=l+r>>1;
		build(l,mid,k<<1),build(mid+1,r,k<<1|1);
		tree[k]=max(tree[k<<1],tree[k<<1|1]);
	}
	void build2(int l,int r,int k){
		if(l==r){
			tree[k]=b[l];
			return;
		}
		int mid=l+r>>1;
		build2(l,mid,k<<1),build2(mid+1,r,k<<1|1);
		tree[k]=max(tree[k<<1],tree[k<<1|1]);
	}
	int query(int l,int r,int L,int R,int k){
		if(L<=l&&r<=R){
			return tree[k];
		}
		int mid=l+r>>1,sum=0;
		if(L<=mid) sum=query(l,mid,L,R,k<<1);
		if(R>mid) sum=max(sum,query(mid+1,r,L,R,k<<1|1));
		return sum;
	}
}A,B;
int ans=0;
signed main(){
	fl();
	T=read();
	n=read();
	For(i,1,n,1) a[i]=read();
	For(i,1,n,1) b[i]=read();
	A.build(1,n,1);B.build2(1,n,1);
	Q=read();
	while(Q--){
		ans=0;
		int l=read(),r=read();
		For(p,l,r,1){
			For(q,p,r,1){
				ans+=A.query(1,n,p,q,1)*B.query(1,n,p,q,1);
			}
		}
		write(ans);puts("");
	}
	return 0;
}

