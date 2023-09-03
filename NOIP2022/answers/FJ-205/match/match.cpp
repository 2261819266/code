#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int T;
int n;
int Q;
int ql[300000];
int qr[300000];
int a[300000];
int b[300000];

ull sta[300000][30];
ull stb[300000][30];

ull ans;
ull noma, nomb;

ull query(int l, int r){
	ull ma, mb;
	int k;
	k = log2(r - l);
	
	ma = max(sta[l][k], sta[r-(1<<k)+1][k]);
	mb = max(stb[l][k], stb[r-(1<<k)+1][k]);
	
	return ma * mb;
}

int main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	scanf("%d%d", &T, &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
		sta[i][0] = a[i];
	}
	for(int i = 1; i <= n; ++i){
		scanf("%d", &b[i]);
		stb[i][0] = b[i];
	}
	scanf("%d", &Q);
	for(int i = 1; i <= Q; ++i){
		scanf("%d%d", &ql[i], &qr[i]);
	}
	
	for(int j = 1; j <= 25; ++j){
		for(int i = 1; i + (1 << j) <= n + 1000; ++i){
			sta[i][j] = max(sta[i][j-1], sta[i+(1<<(j-1))][j-1]);
			stb[i][j] = max(stb[i][j-1], stb[i+(1<<(j-1))][j-1]);
		}
	}
	
	for(int q = 1; q <= Q; ++q){
		ans = 0;
		for(int i = ql[q]; i <= qr[q]; ++i){
			for(int j = i; j <= qr[q]; ++j){
				ans += query(i, j);
			}
		}
		printf("%llu\n", ans);
	}

return 0;
}

