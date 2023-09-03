#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

struct ST{
	int n;
	int s[1000005], a[250005];
	void pushup(int p){
		s[p] = max(s[p*2], s[p*2+1]);
	};
	void init(int aa[], int nn){
		n=nn;for (int i = 1; i <= nn; i++) a[i] = aa[i];
	};
	void build(int l, int r, int p){
		if (l == r){
			s[p]=a[l];return ;
		}
		int mid = (l+r)/2;
		build(l, mid, p*2);build(mid+1, r, p*2+1);
		pushup(p);
	};
	int query(int l, int r, int L, int R, int p){
		if (L <= l && r <= R){
			return s[p];
		}
		int mid = (l+r)/2, ans = 0;
		if (L <= mid) ans = max(ans, query(l, mid, L, R, p*2));
		if (mid < R) ans = max(ans, query(mid+1, r, L, R, p*2+1));
		return ans;
	}
}mxa, mxb;

int ID, n;
int a[250005], b[250005];
int q;
int l, r;
ull sum;

signed main(){
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> ID >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	mxa.init(a, n);mxa.build(1, n, 1);
	for (int i = 1; i <= n; i++) cin >> b[i];
	mxb.init(b, n);mxb.build(1, n, 1);
	cin >> q;
	while(q--){
		sum=0;
		cin >> l >> r;
		for (int x = l; x <= r; x++){
			for (int y = x; y <= r; y++){
//				cout << x << ' ' << y << ' '<< getma(x, y) << ' ' << getmb(x, y) << '\n';
				sum+=(ull)mxa.query(1, n, x, y, 1)*(ull)mxb.query(1, n, x,y, 1);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
