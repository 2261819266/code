#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAXN = 1000 + 10;
const LL MOD = 998244353;
LL T, id;
char A[MAXN][MAXN];
LL L[MAXN][MAXN]; // '0' length minus(-) 1
LL colL[MAXN][MAXN], colR[MAXN][MAXN], tot[MAXN]; // the data of j-th column
LL N, M, C, F;
LL ansC, ansF;

// duo ce Clear
void init() {
	for(int i = 1; i <= N; i++) L[i][M + 1] = -1;
	for(int j = M; j >= 1; j--) 
		for(int i = 1; i <= N; i++) {
			if(A[i][j] == '1')
				L[i][j] = -1;
			else
				L[i][j] = L[i][j + 1] + 1;
		}
	LL las = 0;
	for(int j = M; j >= 1; j--) {
		las = 0;
		for(int i = 1; i <= N; i++) {
			if(A[i][j] == '1') {
				if(las) {
					tot[j]++;
					colL[j][tot[j]] = las;
					colR[j][tot[j]] = i - 1;
					las = 0;
				}
			} else
				if(A[i - 1][j] == '1' || i == 1)
					las = i;
		}
		if(las) {
			tot[j]++;
			colL[j][tot[j]] = las;
			colR[j][tot[j]] = N;
		}
	}
		
}
void calc() {
	LL SC = 0, SF = 0, sum = 0;
	for(int j = 1; j <= M; j++) {
		for(int k = 1; k <= tot[j]; k++) {
			SC = 0, sum = 0;
			LL l = colL[j][k], r = colR[j][k];
			for(int i = l; i <= r; i++) { // C
				if(i != l)
					SC += sum * L[i][j];
				sum += L[i][j];
			}
			for(int i = l + 1; i <= r; i++) // l + 1
				SC -= L[i][j] * L[i - 1][j];
			ansC = (ansC + SC) % MOD;
		}
	}
	
	for(int j = 1; j <= M; j++) {
		for(int k = 1; k <= tot[j]; k++) {
			SF = 0, sum = 0;
			LL l = colL[j][k], r = colR[j][k];
//			LL len = r - l + 1;
			for(int i = l; i <= r; i++) {
				if(i != l)
					SF += sum * L[i][j] * (r - i);
				sum += L[i][j];
			}
			for(int i = l + 1; i <= r; i++)
				SF -= L[i][j] * L[i - 1][j] * (r - i);
			ansF = (ansF + SF) % MOD;
		}
	}
}
int main() {
	#ifdef test
		freopen("test.txt", "r", stdin);
	#else
		freopen("plant.in", "r", stdin);
		freopen("plant.out", "w", stdout);
	#endif
	
	cin >> T >> id;
	while(T--) {
		ansC = ansF = 0;
		memset(L, 0, sizeof(L));
		memset(tot, 0, sizeof(tot));
		memset(A, false, sizeof(A));
		scanf("%lld %lld %lld %lld", &N, &M, &C, &F);
		for(int i = 1; i <= N; i++) 
			scanf("%s", A[i] + 1);
		init();
		calc();
		printf("%lld %lld\n", C * ansC, F * ansF);
	}
	return 0;
}

