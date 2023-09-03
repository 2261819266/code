#include <iostream>
#include <cstdio>
#define ll long long
#include <memory.h>
using namespace std;
const int maxn = 1007;
int c, f;				//Enabled plant
int gd[maxn][maxn];		//Garden
int T, id, n, m;		//Test, ID, Line, Column
ll ansC, ansF;			//Answer

int main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
//	freopen("CON", "w", stdout);
	scanf("%d%d", &T, &id);
	
	for(int t = 0; t < T; t++) {
		//reset
		memset(gd, 0, sizeof(gd));
		ansC = ansF = 0;
		//input
		scanf("%d%d%d%d", &n, &m, &c, &f);
		for(int i = 1; i <= n; i++) {
			getchar();
			for(int j = 1; j <= m; j++)
				gd[i][j] = getchar() - 48;
		}
		//format
		for(int i = n; i >= 1; i--) {
			for(int j = m; j >= 1; j--) {
				if(gd[i][j] == 0)	gd[i][j] = gd[i][j + 1] + 1;
				else gd[i][j] = 0;
			}
		}

//		debug
//		for(int i = 1; i <= n; i++) {
//			for(int j = 1; j <= m; j++)
//				cout << gd[i][j];
//			cout << endl;
//		}
			
		//Char C (c: False will skip)
		if(c) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					if(gd[i][j] > 1 && gd[i + 1][j] && gd[i + 2][j]) {
						//line beginning; find boundary; next line
						for(int ln = i + 2; gd[ln][j] > 0; ln++) {
							ansC += (gd[ln][j] - 1) * (gd[i][j] - 1);
							ansC %= 998244353; 
						}
					}
				}
			}
		}
		//Char F (f: False will skip)
		if(f) {
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= m; j++) {
					if(gd[i][j] > 1 && gd[i + 1][j] && gd[i + 2][j] && gd[i + 3][j]) {
						int maxln = i + 2;
						for( ;gd[maxln + 2][j]; maxln++);	//find column boundary
						//same as Char C
						for(int ln = i + 2; ln <= maxln; ln++) {
							ansF += (gd[ln][j] - 1) * (gd[i][j] - 1) * (maxln - ln + 1);
							ansF %= 998244353;
						}
					}
				}
			}
		}
		
		printf("%lld %lld\n", ansC, ansF);
	}
	return 0;
}
/*
 *  p.s. ¾ºÈüÒ²ÓÐhomo£¨±¯£©
 *
 */
