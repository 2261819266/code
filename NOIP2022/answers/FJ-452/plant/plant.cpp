#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
int T, id;
int n, m, c, f;
int nx, ny;
char ch[1005][1005];
int cx[1005][1005], cy[1005][1005];
const int mod = 998244353;
long long per, vc, vf;

int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> T >> id;
	while(T--){
		cin >> n >> m >> c >> f;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				cin >> ch[i][j];
			}
		}
		if(!c && !f){
			cout << "0 0" << endl;
		}
		else
			ny = m + 1;
			for(int i = 1; i <= n; i++){
				for(int j = m; j >= 1; j--){
					if(ch[i][j] == '1') ny = j;
					else cx[i][j] = ny;
				}
				ny = m + 1;
			}
			nx = n + 1;
			for(int i = 1; i <= m; i++){
				for(int j = n; j >= 1; j--){
					if(ch[j][i] == '1') nx = j;
					else cy[j][i] = nx;
				}
				nx = n + 1;
			}
			for(int k = 1; k <= m; k++){ 
				int x1 = 1, x2 = 0;
				per = 0;
				while(x1 + 1 < n){
					if(ch[x1][k] == '0'){
						x2 = x1 + 1;
						while(ch[x2][k] == '0' && x2 <= n){
							if(x1 + 1 < x2){
								per = ((cx[x1][k] - 1 - k) % mod) * ((cx[x2][k] - 1 - k) % mod) % mod;
								vc = (vc + per) % mod;
								vf = (vf + per * (cy[x2][k] - 1 - x2)) % mod;
							}
							x2++;
						}
					}
					x1++;
				}
			}
			cout << (c * vc) % mod << ' ' << (f * vf) % mod << endl;
	}
	return 0;
}
