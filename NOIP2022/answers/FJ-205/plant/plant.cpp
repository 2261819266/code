#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;

int T, id;
int n, m, c, f;

char rein;
bool garden[1200][1200];
long long cntc1, cntc2;
long long cntf1, cntf2, cntf3;

long long ansc;
long long ansf;

int main(){
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	
	scanf("%d%d", &T, &id);
	while(T--){
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				cin>>rein;
				garden[i][j] = rein - '0';
			}
		}
		
		if(c){
			for(int y0 = 1; y0 <= m; ++y0){
				for(int x1 = 1; x1 <= n; ++x1){
					cntc1 = 0;
					if(garden[x1][y0]) continue;
					if(garden[x1+1][y0]) continue;
					if(garden[x1+2][y0]) continue;
					if(garden[x1][y0+1]) continue;
					for(int y1 = y0+1; y1 <= m; ++y1){
						if(garden[x1][y1]) break;
						++cntc1;
					}
					
					for(int x2 = x1 + 2; x2 <= n; ++x2){
						if(garden[x2][y0+1]) continue;
						bool back;
						back = 0;
						for(int i = x1 + 3; i <= x2; ++i){
							if(garden[i][y0]){
								back = 1;
								break;
							}
						}
						if(back) break;
						
						cntc2 = 0;
						for(int y2 = y0 + 1; y2 <= m; ++y2){
							if(garden[x2][y2]) break;
							++cntc2;
						}
						
						ansc += (cntc1 * cntc2) % Mod;
						ansc %= Mod;
					}
				}
			}
			printf("%lld ", ansc);
		}
		else
			printf("0 ");
		
		if(f){
			for(int y0 = 1; y0 <= m; ++y0){
				for(int x1 = 1; x1 <= n; ++x1){
					cntf1 = 0;
					if(garden[x1][y0]) continue;
					if(garden[x1+1][y0]) continue;
					if(garden[x1+2][y0]) continue;
					if(garden[x1][y0+1]) continue;
					for(int y1 = y0+1; y1 <= m; ++y1){
						if(garden[x1][y1]) break;
						++cntf1;
					}
					
					for(int x2 = x1 + 2; x2 <= n; ++x2){
						if(garden[x2][y0+1]) continue;
						bool back;
						back = 0;
						for(int i = x1 + 3; i <= x2; ++i){
							if(garden[i][y0]){
								back = 1;
								break;
							}
						}
						if(back) break;
						
						cntf2 = 0;
						for(int y2 = y0 + 1; y2 <= m; ++y2){
							if(garden[x2][y2]) break;
							++cntf2;
						}
						
						cntf3 = 0;
						for(int x3 = x2 + 1; x3 <= n; ++x3){
							if(garden[x3][y0]) break;
							++cntf3;
						}
						
						ansf += (((cntf1 * cntf2) % Mod) * cntf3) % Mod;
						ansf %= Mod;
					}
				}
			}
			printf("%lld\n", ansf);
		}
		else
			printf("0\n");
	}

return 0;
}

