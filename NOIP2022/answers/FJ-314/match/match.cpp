#include <iostream>
#include <cstdio>
using namespace std;
int t,n,q,a[250010],b[250010];
struct SegTree{
	int tree[1000010];
	inline void pushup(int id) {tree[id]=max(tree[id<<1],tree[id<<1|1]);}
	void build(int id,int l,int r,int *arr){
		if(l==r)	return tree[id] = arr[l], void();
		int mid = (l + r) >> 1;
		build(id<<1,l,mid,arr),build(id<<1|1,mid+1,r,arr);
		pushup(id);
	}
	int query(int id,int l,int r,int x,int y){
		if(r<x||l>y)	return 0;
		if(x<=l&&r<=y)	return tree[id];
		int mid = (l + r) >> 1,res = 0;
		if(x<=mid)	res = query(id<<1,l,mid,x,y);
		if(mid<y)	res = max(res,query(id<<1|1,mid+1,r,x,y));
		return res;
	}
}sega,segb;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d %d",&t,&n);
	for(int i=1;i<=n;i++)	scanf("%d",a+i);
	for(int i=1;i<=n;i++)	scanf("%d",b+i);
	sega.build(1,1,n,a),segb.build(1,1,n,b);
	scanf("%d",&q);
	while(q--){
		unsigned long long res = 0;
		int l,r;scanf("%d %d",&l,&r);
		for(int x=l;x<=r;x++)
			for(int y=x;y<=r;y++)
				res += sega.query(1,1,n,x,y) * segb.query(1,1,n,x,y);
		printf("%llu\n",res);
	}
	return 0;
}
/* I love zxl forever */

