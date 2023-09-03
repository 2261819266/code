#include<bits/stdc++.h>
using namespace std;

const int N = 1100, P = 998244353;
int T, id;
int a[N][N];
int dis[N][N], add[N][N];
int n, m, c, f;


int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	cin >> T >> id;
	if(id == 1) {
		while(T--) {
			printf("0 0\n");
		}
		return 0;
	}

	if(id == 5) {
		while(T--){
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i = 1; i <= n; i ++) {
			string s;
			cin >> s;
			for(int j = 0; j < m; j ++) {
				a[i][j+1] = s[j] - '0';
			}
		}
			long long va = 0, vb = 0;
			va = (n-2) * (n-1) /2 ;
			va = (va % P * (int)floor(m / 3) % P) % P;
			vb = (n-3) * (n-2) / 2;
			vb = (vb % P * (int)floor(m / 3) % P) % P;
			printf("%lld %lld\n", va, vb);
		}
		return 0;
	}
	if(id == 6) {
		while(T--){
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i = 1; i <= n; i ++) {
			string s;
			cin >> s;
			for(int j = 0; j < m; j ++) {
				a[i][j+1] = s[j] - '0';
			}
		}
			long long va = 0;
			for(int j = 1; j < m; j ++) {
				va = (va % P + j * j % P) % P;
			}
			va = (va % P * (int)floor(n / 4) % P) % P;
			printf("%lld 0\n", va);
		}
		return 0;
	}
	if(id == 15) {
		while(T --) {
			scanf("%d%d%d%d", &n, &m, &c, &f);
			for(int i = 1; i <= n; i ++) {
				string s;
				cin >> s;
				for(int j = 0; j < m; j ++) {
					a[i][j+1] = s[j] - '0';
					add[i][j+1] = add[i-1][j+1] + a[i][j+1];
				}
			}


			for(int i = 1; i <= n; i ++) {
				for(int j = 1; j<= m; j ++) {
					int k = j + 1;
					while(a[i][k] == 0 && k <= m) k ++;
					dis[i][j] = k - j - 1;
//				cout << dis[i][j];
				}
//			cout << endl;
			}


			long long va = 0, vb = 0;
			for(int j = 1; j <= m; j ++) {
				for(int i = 1; i <= n; i ++) {
					for(int k = i + 2; k <= n; k ++) {
						if(add[k][j] - add[i-1][j] == 0) {
							va = (va % P + (dis[i][j] % P * dis[k][j] % P)) % P;
						}
					}

				}
				printf("%lld 0\n", va);
			}
			return 0;
		}
	}

	while(T --) {
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i = 1; i <= n; i ++) {
			string s;
			cin >> s;
			for(int j = 0; j < m; j ++) {
				a[i][j+1] = s[j] - '0';
				add[i][j+1] = add[i-1][j+1] + a[i][j+1];
			}
		}


		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j<= m; j ++) {
				int k = j + 1;
				while(a[i][k] == 0 && k <= m) k ++;
				dis[i][j] = k - j - 1;
//				cout << dis[i][j];
			}
//			cout << endl;
		}


		long long va = 0, vb = 0;
		for(int j = 1; j <= m; j ++) {
			for(int i = 1; i <= n; i ++) {
				for(int k = i + 2; k <= n; k ++) {
					if(add[k][j] - add[i-1][j] == 0) {
						va = (va % P + (dis[i][j] % P * dis[k][j] % P)) % P;
					}
				}
				for(int k = i + 3; k <= n; k ++)
					if(add[k][j] - add[i - 1][j] == 0)
						for(int k2 = i + 2; k2 <= k - 1; k2 ++)
							vb = (vb % P +(dis[i][j] % P * dis[k2][j] % P)) % P;
			}
		}
		printf("%lld %lld\n", va, vb);
	}

	return 0;
}
//noip rp+++++++