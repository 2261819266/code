// Per aspera ad astra.
// 1004535809
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define re register
#define ll long long
#define ull unsigned long long
using namespace std;
const int P = 998244353, oo = 0x3f3f3f3f, N = 1e3;
inline int Add(re int x, re int y) {return x + y < P ? x + y : x + y - P;}
inline int Sub(re int x, re int y) {return x - y < 0 ? x - y + P : x - y;}
inline int Mul(re int x, re int y) {re ull z = 1llu * x * y; return z < P ? z : z % P;}
int n, m, c, f, AnsC, AnsF, A[N + 5][N + 5], B[N + 5][N + 5], C[N + 5][N + 5]; char S[N + 5];
signed main() {
	freopen("plant.in", "r", stdin);
	freopen("plant.out", "w", stdout);
	re int _;
	scanf("%d%*d", &_);
	while (_--) {
		scanf("%d%d%d%d", &n, &m, &c, &f);
		AnsC = AnsF = 0;
		for (re int i = 0; i <= n + 1; ++i) {
			for (re int j = 0; j <= n + 1; ++j) A[i][j] = 1; 
		}
		for (re int i = 1; i <= n; ++i) {
			scanf("%s", S + 1);
			for (re int j = 1; j <= m; ++j) A[i][j] = S[j] - 48;
		}
		for (re int i = 1; i <= n; ++i) {
			for (re int j = m; j; --j) B[i][j] = (A[i][j] ? 0 : B[i][j + 1] + 1);
		}
		for (re int i = 1; i <= n; ++i) {
			for (re int j = 1; j <= m; ++j) --B[i][j];
		} 
		for (re int i = 1; i <= m; ++i) {
			for (re int j = 1; j <= n; ++j) B[j][i] = (A[j][i] ? 0 : B[j - 1][i] + B[j][i]);
		}
		for (re int i = 1; i <= m; ++i) {
			for (re int j = n; j; --j) C[j][i] = (A[j][i] ? 0 : C[j + 1][i] + 1);
		}
		for (re int i = 1; i <= n; ++i) {
			for (re int j = 1; j <= m; ++j) --C[i][j];
		} 
		for (re int i = 1; i <= n; ++i) {
			for (re int j = 1; j <= m; ++j) if (!A[i][j] && !A[i - 1][j]) {
				AnsC = Add(AnsC, Mul(B[i][j] - B[i - 1][j], B[i - 2][j]));
				//printf("(%d, %d)%d", i, j, Mul(B[i][j] - B[i - 1][j], B[i - 2][j]));
			}
		}
		//putchar('\n');
		for (re int i = 1; i <= n; ++i) {
			for (re int j = 1; j <= m; ++j) if (!A[i][j] && !A[i - 1][j]) {
				AnsF = Add(AnsF, Mul(Mul(B[i][j] - B[i - 1][j], B[i - 2][j]), C[i][j]));
				//printf("(%d, %d)%d", i, j, Mul(Mul(B[i][j] - B[i - 1][j], B[i - 2][j]), C[i][j]));
			}
		}
		//putchar('\n');
		printf("%d %d\n", c ? AnsC : 0, f ? AnsF : 0);
	}
	return 392699 ^ 392699;
}
