#include <bits/stdc++.h>
using namespace std;

int n, m;
int rein1, rein2;

int tot;
int Ver[6000000];
int Head[600000];
int Next[6000000];
void add(int x, int y){
	Ver[++tot] = y;
	Next[tot] = Head[x];
	Head[x] = tot;
	
	Ver[++tot] = x;
	Next[tot] = Head[y];
	Head[y] = tot;
	return;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d%d", &rein1, &rein2);
		add(rein1, rein2);
	}
	
	

return 0;
}

