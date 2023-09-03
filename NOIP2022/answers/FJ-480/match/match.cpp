#include <cstdio>
#define N 250010
#define ll long long

int max(int a,int b){
	return a < b ? b : a;
}
int n,a[N],b[N];
ll f[3010][3010];
struct SegTree{
	int l,r,mi;
	#define l1(x) t1[x].l
	#define l2(x) t2[x].l
	#define r1(x) t1[x].r
	#define r2(x) t2[x].r
	#define mi1(x) t1[x].mi
	#define mi2(x) t2[x].mi
}t1[N * 4],t2[N * 4];
void build1(int p,int l,int r){
	l1(p) = l,r1(p) = r;
	if (l == r){
		mi1(p) = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build1(p * 2,l,mid);
	build1(p * 2 + 1,mid + 1,r);
	mi1(p) = max(mi1(p * 2),mi1(p * 2 + 1));
}
void build2(int p,int l,int r){
	l2(p) = l,r2(p) = r;
	if (l == r){
		mi2(p) = b[l];
		return;
	}
	int mid = (l + r) / 2;
	build2(p * 2,l,mid);
	build2(p * 2 + 1,mid + 1,r);
	mi2(p)= max(mi2(p * 2),mi2(p * 2 + 1));
}
int query1(int p,int l,int r){
	if (l1(p) >= l && r >= r1(p)) return mi1(p);
	int mid = (l1(p) + r1(p)) / 2,mi = 0;
	if (l <= mid) mi = max(query1(p * 2,l,r),mi);
	if (r > mid) mi = max(query1(p * 2 + 1,l,r),mi);
	return mi;
}

int query2(int p,int l,int r){
	if (l <= l2(p) && r >= r2(p)) return mi2(p);
	int mid = (l2(p) + r2(p)) / 2,mi = 0;
	if (l <= mid) mi = max(query2(p * 2,l,r),mi);
	if (r > mid) mi = max(query2(p * 2 + 1,l,r),mi);
	return mi;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	scanf("%d%d",&T,&n);
	for (int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for (int i = 1;i <= n;i++) scanf("%d",&b[i]);
	build1(1,1,n);
	build2(1,1,n);
	int q;scanf("%d",&q);
	while (q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ll ans = 0;
		for (int p = l;p <= r;p++){
			for (int q = p;q <= r;q++){
				if (!f[p][q]) f[p][q] = (ll)query1(1,p,q) * query2(1,p,q);
				ans += f[p][q];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

