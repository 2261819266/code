#include <iostream>
#include <cstdio>
using namespace std;
int t,id,n,m,cc,ff;
long long ans1=0,ans2=0;
int c[5][2];
int f[5][2];
bool a[1001][1001];
bool ok (bool x) {
	if (x) {
		for (int i=f[1][1]; i<=f[2][1]; i++) {
			if (a [f[1][0]] [i]) {
				return 0;
			}
		}
		for (int i=f[1][0]; i<=f[4][0]; i++) {
			if (a [i] [ f [1] [1] ]) {
				return 0;
			}
		}
		for (int i=f[1][1]; i<=f[3][1]; i++) {
			if (a [f [3][0] ] [i] ) {
				return 0;
			}
		}
		return 1;
	} else {
		for (int i=c[1][1]; i<=c[2][1]; i++) {
			if (a [ c[1][0] ] [i]) {
				return 0;
			}
		}
		for (int i=c[1][0]; i<=c[3][0]; i++) {
			if (a [i] [ c[1][1] ]) {
				return 0;
			}
		}
		for (int i=c[3][1]; i<=c[4][1]; i++) {
			if (a [c[3][0]] [i]) {
				return 0;
			}
		}
		return 1;
	}
}
void ccc () {
	for (int i=1; i<=n-2; i++) {
		for (int j=1; j<m; j++) {
			c[1][0]=i;
			c[1][1]=j;
			for (int k=j+1; k<=m; k++) {
				c[2][0]=i;
				c[2][1]=k;
				for (int u=i+2; u<=n; u++) {
					c[3][0]=u;
					c[3][1]=j;
					for (int o=j+1; o<=m; o++) {
						c[4][0]=u;
						c[4][1]=o;
						if (ok(0)) {
							ans1++;
							ans1%=998244353;
						}
					}
				}
			}
		}
	}
}
void fff () {
	for (int i=1; i<=n-3; i++) {
		for (int j=1; j<m; j++) {
			f[1][0]=i;
			f[1][1]=j;
			for (int k=j+1; k<=m; k++) {
				f[2][0]=i;
				f[2][1]=k;
				for (int u=i+2; u<n; u++) {
					for (int o=j+1; o<=m; o++) {
						f[3][0]=u;
						f[3][1]=o;
						for (int p=u+1; p<=n; p++) {
							f[4][0]=p;
							f[4][1]=j;
							if (ok(1)) {
								ans2++;
								ans2%=998244353;
							}
						}
					}
				}
			}
		}
	}
}
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin >> t >> id;
	for (int i=1; i<=t; i++) {
		cin >> n >> m >> cc >> ff;
		for (int j=1; j<=n; j++) {
			string s;
			cin >> s;
			for (int k=1; k<=m; k++) {
				a[j][k]=s[k-1]-'0';
			}
		}
		ccc();
		fff();
		cout << ans1*cc%998244353 << ' ' << ans2*ff%998244353 << endl;
		ans1=ans2=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
