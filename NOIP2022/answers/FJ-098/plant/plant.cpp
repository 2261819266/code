#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

inline int read() {
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
	return f*s;
}

inline ll readll() {
	ll s=0ll,f=1ll;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1ll;ch=getchar();}
	while(ch>='0'&&ch<='9')s=(s<<1)+(s<<3)+ch-'0',ch=getchar();
	return f*s;
}

const ll mod = 998244353;

int t, id;

long long c, f, ansc, ansf;
int n, m;
char a[1005][1005];
ll y[1005][1005], dpgm[1005][1005], dpc[1005][1005], dp2[1005][1005], sdp2[1005][1005], dp3[1005][1005];
ll dpf[1005][1005];
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	t = read(), id = read();
	while(t --) {
		memset(y, 0, sizeof y);
		memset(dpgm, 0, sizeof dpgm);
		memset(dpc, 0, sizeof dpc);
		memset(dp2, 0, sizeof dp2);
		memset(sdp2, 0, sizeof sdp2);
		memset(dp3, 0, sizeof dp3);
		memset(dpf, 0, sizeof dpf);
		ansc = ansf = 0;
		n = read(), m = read();
		c = readll(), f = readll();
		for(int i = 1; i <= n; ++ i) cin >> (a[i] + 1);
		for(int i = 1; i <= n; ++ i) {
			for(int j = m; j >= 1; j --) {
				if(a[i][j] == '1') {
					y[i][j] = 0; continue;
				}
				else {
					y[i][j] = y[i][j + 1] + 1;
				}
			}
		}/*
		for(int i = 1;i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				cout << y[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		//gama
		for(int i = 2; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				if(a[i][j] == '1') dpgm[i][j] = 0;
				else {
					if(y[i - 1][j])dpgm[i][j] = (dpgm[i - 1][j] + y[i - 1][j] - 1) % mod;
				}
			}
		}/*
		for(int i = 1;i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				cout << dpgm[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		//c
		for(int i = 2; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				if(a[i][j] == '1') {
					dp2[i][j] = sdp2[i][j] = 0;
					continue;
				}
				else dp2[i][j] = dpgm[i - 1][j], sdp2[i][j] = (sdp2[i][j - 1] + dp2[i][j]) % mod;
				dpc[i][j] = sdp2[i][j - 1];
				ansc += dpc[i][j]; ansc %= mod;
			}
		}/*
		for(int i = 1;i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				cout << dpc[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		cout << (c * ansc) << " ";
		for(int i = 4; i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				if(a[i][j] != '1' && y[i - 1][j]) {
					dpf[i][j] = dpgm[i - 2][j] * (y[i - 1][j] - 1);
					dpf[i][j] %= mod;
					dpf[i][j] += dpf[i - 1][j];
					dpf[i][j] %= mod;
					ansf += dpf[i][j];
					ansf %= mod;
				}
			}
		}/*
		for(int i = 1;i <= n; i ++) {
			for(int j = 1; j <= m; j ++) {
				cout << dpf[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
		cout << (f * ansf) << endl;
	}
}
