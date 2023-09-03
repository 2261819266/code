#include <bits/stdc++.h>

#define Register_int using
#define AK namespace
#define NOIP std

Register_int AK NOIP;

// Register_int AK NOIP !!!!!!

/*
I now how to solve T3
But I forgot how to solve SCC(bridge)
Who can teach me tarjan /ll

my 100 score /ll

I can't AK NOIP /kk
*/

typedef long long ll;

const int MAXN = 5e5 + 10;
const int mod = 1e9 + 7;

int n, m;

ll p2[MAXN], sum[MAXN], ans;

int main() {
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	scanf("%d%d", &n, &m), p2[0] = 1;
	for (int i = 1; i <= n; i++) p2[i] = (p2[i - 1] << 1) % mod;
	for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + p2[i] - 1) % mod;
	for (int i = 1; i <= n; i++) ans = (ans * 2 + p2[i - 1] + sum[i - 1]) % mod;
	printf("%lld", ans);
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
