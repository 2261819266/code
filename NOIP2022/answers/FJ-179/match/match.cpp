#include <cstdio>
#include <algorithm>

using namespace std;

inline Max(int a,int b) {
	return a > b ? a : b;
}

const int MaxN = 250001;

int T,n,Q;

int arrA[MaxN];
int arrB[MaxN];
int treeA[MaxN << 2],treeB[MaxN << 2];

void buildTree(int l,int r,int node = 1) {
	int ls = node << 1;
	int rs = node << 1 | 1;
	
	if(l == r) {
		treeA[node] = arrA[l];
	}
	else {
		int mid = l + ((r - l) >> 1);
		printf("%d %d\n",l,mid);
		printf("%d %d\n",mid + 1,r);
		buildTree(l,mid,ls);
		
		
		buildTree(mid + 1,r,rs);
		
		treeA[node] = Max(treeA[ls],treeA[rs]);
	}
}

int query(int l,int r,int node = 1,int L = 1,int R = n) {
	printf("%d %d %d\n",node,L,R);
	int ls = node << 1;
	int rs = node << 1 | 1;
	int mid = l + ((r - l) >> 1);
	
	if(l == r || (L >= l && R <= r)) {
		return treeA[node];
	}
	else {
		int a,b;
		if(L >= l) {
			a = query(l,r,ls,l,mid);
		}
		if(R <= r) {
			b = query(l,r,rs,mid + 1,r);
		}		
		
		return Max(a,b);
	}
}

int main() {
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,k;
	int l,r;
	scanf("%d %d",&T,&n);
	//buildTree(1,n);
	for(int i = 1;i <= n;++i) {
		scanf("%d",&k);
		arrA[i] = k;
	}
	for(int i = 1;i <= n;++i) {
		scanf("%d",&k);
		arrB[i] = k;
	}
	unsigned long long sum = 0;
	scanf("%d",&Q);
	for(int i = 1;i <= Q;++i) {
		scanf("%d %d",&l,&r);
		sum = 0;
		for(int p = l;p <= r;++p) {
			for(int q = p;q <= r;++q) {
				int maxA = -1,maxB = -1;
				for(int k = p;k <= q;++k) {
					if(arrA[k] > maxA) {
						maxA = arrA[k];
					}
					if(arrB[k] > maxB) {
						maxB = arrB[k];
					}
				}
				sum += maxA * maxB;
			}
		}
		printf("%lld\n",sum);
	}
	
	return 0;
}
