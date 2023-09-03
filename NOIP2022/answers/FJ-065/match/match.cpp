#include<bits/stdc++.h>
using namespace std;
#define fr(i,j,k) for(int i=j;i<=k;i++)
#define dr(i,j,k) for(int i=j;i>=k;i--)
#define int long long
const int N = 1e5+10;
void file(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	return;
}
inline int read(){
	int x=0,f=1;char ch = getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f = -1;
		ch = getchar();
	}
	while(ch>='0'&&ch<='9')x = x*10+ch-'0',ch = getchar();
	return x*f;
}
//------------------------------------
int T,n;
int a[N],b[N];
int Q;
int tree1[N<<2],tree2[N<<2];
//------------------------------------
#define root 1,n,1
#define ls k<<1
#define rs k<<1|1
#define update1 tree1[k] = max(tree1[ls],tree1[rs])
#define update2 tree2[k] = max(tree2[ls],tree2[rs])
void build1(int l,int r,int k){
	if(l==r){
		tree1[k] = a[l];
		return;
	}
	int mid = (l+r)>>1;
	build1(l,mid,ls);build1(mid+1,r,rs);
	update1;
	return;
}
int qjcx1(int l,int r,int k,int x,int y){
	if(x<=l&&y>=r)return tree1[k];
	int mid = (l+r)>>1;
	int ans=0;
	if(x<=mid)ans = max(ans,qjcx1(l,mid,ls,x,y));
	if(y>mid)ans = max(ans,qjcx1(mid+1,r,rs,x,y));
	return ans; 
}
//---------------------------------------
void build2(int l,int r,int k){
	if(l==r){
		tree2[k] = b[l];
		return;
	}
	int mid = (l+r)>>1;
	build2(l,mid,ls);build2(mid+1,r,rs);
	update2;
	return;
}
int qjcx2(int l,int r,int k,int x,int y){
	if(x<=l&&y>=r)return tree2[k];
	int mid = (l+r)>>1;
	int ans=0;
	if(x<=mid)ans = max(ans,qjcx2(l,mid,ls,x,y));
	if(y>mid)ans = max(ans,qjcx2(mid+1,r,rs,x,y));
	return ans; 
}
//------------------------------------
signed main(){
	file();
	T=read();n=read();
	fr(i,1,n)a[i] = read();
	fr(i,1,n)b[i] = read();
	build1(root);build2(root);
	Q=read();
	while(Q--){
		int x,y,sum=0;
		x = read();y=read();
		fr(i,x,y)fr(j,i,y){
			sum+=qjcx1(root,i,j)*qjcx2(root,i,j);
		}
		printf("%lld\n",sum);
	}
	return 0;
}

