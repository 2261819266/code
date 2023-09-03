#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int long long
#define lc l,mid,p*2
#define rc mid+1,r,p*2+1
const int N = 1e5+10;
const int inf = INT_MAX;
int read(){
	char ch=getchar();
	int f=1,s=0;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return f*s;
}
int t,n,Q;
int a[N],b[N],c[N],d[N];
ull ans;
void build1(int l,int r,int p){
	if(l==r){
		c[p]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build1(lc);
	build1(rc);
	c[p]=max(c[p*2],c[p*2+1]);
}
void build2(int l,int r,int p){
	if(l==r){
		d[p]=b[l];
		return;
	}
	int mid=(l+r)/2;
	build2(lc);
	build2(rc);
	d[p]=max(d[p*2],d[p*2+1]);
}
int query1(int L,int R,int l,int r,int p){
	if(L<=l&&r<=R){
		return c[p];
	}
	int mid=(l+r)/2;
	ull sum=0;
	if(L<=mid)sum=max(sum,(ull)query1(L,R,lc));
	if(R>mid)sum=max(sum,(ull)query1(L,R,rc));
	return sum;
}
int query2(int L,int R,int l,int r,int p){
	if(L<=l&&r<=R){
		return d[p];
	}
	int mid=(l+r)/2;
	ull sum=0;
	if(L<=mid)sum=max(sum,(ull)query2(L,R,lc));
	if(R>mid)sum=max(sum,(ull)query2(L,R,rc));
	return sum;
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	t=read(),n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	build1(1,n,1);
	build2(1,n,1);
//	cout<<query1(1,5,1,n,1)<<'\n';
	Q=read();
	while(Q--){
		int l=read(),r=read();
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++){
				ans=ans+(ull)query1(p,q,1,n,1)*(ull)query2(p,q,1,n,1);
			}
		cout<<ans<<'\n';
//		printf("%u\n",ans);
	}
	return 0;
}

