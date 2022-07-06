#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2.5e7 + 10;
const int Mod = 1e9 + 7;
int N;
inline int Pow(int A, int B) {
	register int Ans = 1;
	while (B) {
		if (B & 1)
			Ans = 1ll * Ans * A % Mod;
		A = 1ll * A * A % Mod;
		B >>= 1;
	}
	return Ans;
}
bool P[MaxN];
int Ans[MaxN], Prime[5000000], Ps, Totans = 1;
int main() {
	// freopen("resign.in", "r", stdin);
	// freopen("resign.out", "w", stdout);
	scanf("%d", &N);
	for (register int i = 2; i <= N; ++i) {
		if (not P[i])
			Ans[i] = Pow(Prime[++Ps] = i, N);
		for (register int j = 1; j <= Ps; ++j) {
			register int S = i * Prime[j];
			if (S > N)
				break;
			P[S] = true;
			Ans[S] = 1ll * Ans[i] * Ans[Prime[j]] % Mod;
			if (i % Prime[j] == 0)
				break;
		}
	}
	for (register int i = 2; i <= N; ++i)
		Totans ^= Ans[i];
	return not printf("%d\n", Totans);
}