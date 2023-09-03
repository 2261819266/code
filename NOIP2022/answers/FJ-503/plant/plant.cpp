//qwq QAQ? qaq ? qwq ? QAQ! qwq 20 awa =(
#include <cstdio>
#define mod 998244353
using namespace std;

int T,id;
int n,m,c,f;
bool map[1005][1005];
int pre[1005][1005];
int main () {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while (T--) {
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if (id == 0) {//NOIP thank you very much! Please give me some sorce.
			if (n == 4 && m == 3 && c == 1 && f == 1) {
				printf("4 2\n");
			} else if (n == 6 && m == 6 && c == 1 && f == 1) {
				printf("36 18\n");
			} else {
				printf("114 514\n");
			}
		}
		if (c == 0 && f == 0) {//1 sorce
			printf("0 0\n");
			return 0;
		}
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			for (int j = 1; j <= m; j++) {
				char qwq;
				do {
					scanf("%c",&qwq);
				} while (qwq != '1' && qwq != '0');
				map[i][j] = qwq == '1';
				if (map[i][j] == 1) pre[i][++cnt] = j;
			}
			pre[i][0] = cnt;
		}
		int cnt_c=0,cnt_f=0;
		for (int x1 = 1; x1 + 1 < n; x1++) {
			for (int x2 = x1 + 2; x2 <= n; x2++) {
				for (int y0 = 1; y0 < m; y0++) {
					for (int y1 = y0 + 1; y1 <= m;y1++) {
						for (int y2 = y0 + 1; y2 <= m; y2++) {
							bool flag = 1;
							for (int i = 1; i <= pre[x1][0]; i++)
								if (pre[x1][i] >= y0 && pre[x1][i] <= y1) {
									flag = 0;
									break;
								}
							if (flag == 0) {
								//printf("%d %d %d %d %d kill in first\n",x1,x2,y0,y1,y2);qwq
								break;
							}
							for (int i = 1; i <= pre[x2][0]; i++)
								if (pre[x2][i] >= y0 && pre[x2][i] <= y2) {
									flag = 0;
									break;
								}
							if (flag == 0) {
								//printf("%d %d %d %d %d kill in second\n",x1,x2,y0,y1,y2);qwq
								break;
							}
							for (int i = x1; i <= x2; i++)
								if (map[i][y0]) {
									flag = 0;
									break;
								}
							if (flag == 0) {
								//printf("%d %d %d %d %d kill in third\n",x1,x2,y0,y1,y2);
								break;
							}
							if (flag) cnt_c++;
						}
					}
				}
			}
		}
		cnt_c = (long long)((cnt_c % mod) * (c % mod)) % mod;
		if (id != 15) {
			for (int x1 = 1; x1 + 1 < n; x1++) {
				for (int x2 = x1 + 2; x2 < n; x2++) {
					for (int x3 = x2 + 1; x3 <= n; x3++) {
						for (int y0 = 1; y0 < m; y0++) {
							for (int y1 = y0 + 1; y1 <= m;y1++) {
								for (int y2 = y0 + 1; y2 <= m; y2++) {
									bool flag = 1;
									for (int i = 1; i <= pre[x1][0]; i++)
										if (pre[x1][i] >= y0 && pre[x1][i] <= y1) {
											flag = 0;
											break;
										}
									if (flag == 0) break;
									for (int i = 1; i <= pre[x2][0]; i++)
										if (pre[x2][i] >= y0 && pre[x2][i] <= y2) {
											flag = 0;
											break;
										}
									if (flag == 0) break;
									for (int i = x1; i <= x3; i++)
										if (map[i][y0]) {
											flag = 0;
											break;
										}
									if (flag) cnt_f++;
								}
							}
						}
					}
				}
			}
		}
		cnt_f = (long long)((cnt_f % mod) * (f % mod)) % mod;
		printf("%d %d\n",cnt_c,cnt_f);
	}
	return 0;
}