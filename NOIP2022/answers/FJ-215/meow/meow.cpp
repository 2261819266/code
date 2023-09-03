#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1000 + 10; // >= 600
int T, N, M, K;
int sta[MAXN], updown[MAXN], A[MAXN]; // 下标为种类 
int S[MAXN][4]; // 下标为栈 
int ansop, anscla[MAXN], ansone[MAXN], anstwo[MAXN];

void calc() {
	for(int i = 1; i <= M; i++) {
		int cla = A[i], id = (cla + 1) / 2, h = ((cla - 1) ^ 1) + 1;
		if(!sta[cla]) {
			sta[cla] = id;
			if(sta[h]) updown[cla] = 2, S[id][2] = cla; // 2 ding 1 di
			else updown[cla] = 1, S[id][1] = cla;
			ansop++;
			anscla[ansop] = 1;
			ansone[ansop] = id;
		} else {
			if(updown[cla] == 1) {
				ansop++;
				anscla[ansop] = 1;
				ansone[ansop] = N;
				ansop++;
				anscla[ansop] = 2;
				ansone[ansop] = id;
				anstwo[ansop] = N;
				sta[cla] = updown[cla] = 0;
				if(S[id][2]) {
					updown[S[id][2]] = 1;
					S[id][1] = S[id][2];
					S[id][2] = 0;
				}
				
			} else {
				ansop++;
				anscla[ansop] = 1;
				ansone[ansop] = id;
				sta[cla] = updown[cla];
			}
		}
	}
}
int main() {
	#ifdef test
		freopen("test.txt", "r", stdin);
	#else
		freopen("meow.in", "r", stdin);
		freopen("meow.out", "w", stdout);
	#endif
	cin >> T;
	while(T--) {
		scanf("%d %d %d", &N, &M, &K);
		for(int i = 1; i <= M; i++)
			scanf("%d", &A[i]);
		memset(sta, 0, sizeof(sta));
		calc();
		printf("%d\n", ansop);
		for(int i = 1; i <= ansop; i++) 
			if(anscla[i] == 1) 
				printf("%d %d\n", anscla[i], ansone[i]);
			else
				printf("%d %d %d\n", anscla[i], ansone[i], anstwo[i]);
	}
	return 0;
}

