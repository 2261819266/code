#include <bits/stdc++.h>

using namespace std;

const int N=250000;
const int B=19;
#define ULL unsigned long long

int n, q;
ULL RMQ_1[N+10][B], RMQ_2[N+10][B];
int log_2[N+10];

ULL RMQ1(int x, int y) {

	return max(RMQ_1[x][log_2[y-x+1]], RMQ_1[y-(1<<log_2[y-x+1])+1][log_2[y-x+1]]);
}

ULL RMQ2(int x, int y) {

	return max(RMQ_2[x][log_2[y-x+1]], RMQ_2[y-(1<<log_2[y-x+1])+1][log_2[y-x+1]]);
}

void init() {

	for(int i=1; i<=n; i++) log_2[i]=log2(i);

	for(int b=1; b<B; b++)
		for(int i=1; i+(1<<b)-1<=n; i++)
			RMQ_1[i][b]=max(RMQ_1[i][b-1], RMQ_1[i+(1<<(b-1))][b-1]);

	for(int b=1; b<B; b++)
		for(int i=1; i+(1<<b)-1<=n; i++)
			RMQ_2[i][b]=max(RMQ_2[i][b-1], RMQ_2[i+(1<<(b-1))][b-1]);

	return;
}

int main() {

	int T;
	int a, b;

	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);

	scanf("%d%d", &T, &n);

	for(int i=1; i<=n; i++) scanf("%llu", &RMQ_1[i][0]);
	for(int i=1; i<=n; i++) scanf("%llu", &RMQ_2[i][0]);

	init();

	scanf("%d", &q);

	while(q--) {

		scanf("%d%d", &a, &b);

		ULL now_ans=0;

		for(int l=a; l<=b; l++)
			for(int r=l; r<=b; r++)
				now_ans+=RMQ1(l, r)*RMQ2(l, r);

		printf("%llu\n", now_ans);

	}

	return 0;
}
