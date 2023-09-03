#include <bits/stdc++.h>

#define Register_int using
#define AK namespace
#define NOIP std

Register_int AK NOIP;

// Register_int AK NOIP !!!!!!
// But I don't know how to solve T2 qwq

typedef long long ll;

struct node {
	int opt, x, y;
} q[30]; int tot;

int t, n, m, k, id;

int a[14];

deque<int> v[3];

int p3[15], head[3];

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &t);
	if (t % 10 != 3) return 0;
	p3[0] = 1;
	for (int i = 1; i <= 14; i++) p3[i] = p3[i - 1] * 3;
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < m; i++) scanf("%d", &a[i]);
		for (int s = 0; s < p3[m]; s++) {
			tot = 0;
			for (int i = 0; i < 3; i++) v[i].clear(), head[i] = -1;
			for (int i = 0, j; i < m; i++) {
				j = s / p3[i] % 3, q[++tot] = { 1, j + 1 };
				!v[j].empty() && v[j].back() == a[i] ? v[j].pop_back() : v[j].push_back(a[i]);
			}
			while (1) {
				if (!v[0].empty() && !v[1].empty() && v[0][0] == v[1][0]) v[0].pop_front(), v[1].pop_front(), q[++tot] = { 2, 1, 2 };
				else if (!v[1].empty() && !v[2].empty() && v[1][0] == v[2][0]) v[1].pop_front(), v[2].pop_front(), q[++tot] = { 2, 2, 3 };
				else if (!v[0].empty() && !v[2].empty() && v[0][0] == v[2][0]) v[0].pop_front(), v[2].pop_front(), q[++tot] = { 2, 1, 3 };
				else break;
			}
			if (!v[0].empty() || !v[1].empty() || !v[2].empty()) continue;
			printf("%d\n", tot);
			for (int i = 1; i <= tot; i++) {
				if (q[i].opt == 1) printf("1 %d\n", q[i].x);
				else printf("2 %d %d\n", q[i].x, q[i].y);
			}
			break;
		}
	}
}

/*

stCCCCCO %%% zzp hhx cyz wzh %%% CCCCCOrz

hhx AK NOIP!!!!!
zzp can't AK NOIP XD
cyz AK NOIP!!!!!
wzh AK NOIP!!!!!

The god of OIer, hhx
The girl who AKed IOI 24 times
please v me 50pts in NOIP
bless me can get FJ1=
stCCCCCCO %%%% hhx %%%% CCCCCCOrz

*/
