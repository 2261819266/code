#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5+5;
int t,n,a[2][N],q,tr[2][N<<2];
unsigned long long s;
void pushup(int op,int p){
	if(a[op][tr[op][p<<1]]>a[op][tr[op][p<<1|1]]) tr[op][p]=tr[op][p<<1];
	else tr[op][p]=tr[op][p<<1|1];
}
void build(int op,int p,int l,int r){
	if(l==r){
		tr[op][p]=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(op,p<<1,l,mid),build(op,p<<1|1,mid+1,r);
	pushup(op,p);
}
int query(int op,int b,int e,int p,int l,int r){
	if(b<=l&&r<=e) return tr[op][p];
	int mid=(l+r)>>1,ans=0,k;
	if(b<=mid) {
		k=query(op,b,e,p<<1,l,mid);
		if(a[op][k]>a[op][ans]) ans=k;
	}
	if(e>mid) {
		k=query(op,b,e,p<<1|1,mid+1,r);
		if(a[op][k]>a[op][ans]) ans=k;
	}
	return ans;
}
void dfs(int l,int r){
	if(l>r) return ;
	int x=query(0,l,r,1,1,n),y=query(1,l,r,1,1,n);
	int u=min(x,y),v=max(x,y);
	s+=a[0][x]*a[1][y]*(u-l+1)*(r-v+1);
	dfs(l,v-1),dfs(u+1,r);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[0][i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[1][i]);
	build(0,1,1,n),build(1,1,1,n);
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r),s=0;
		for(int i=l;i<=r;i++)
			for(int j=i;j<=r;j++){
				int x=query(0,i,j,1,1,n),y=query(1,i,j,1,1,n);
				s+=(unsigned long long)a[0][x]*(unsigned long long)a[1][y];
			}
//		dfs(l,r);
		cout<<s<<endl;
	}
	return 0;
}
