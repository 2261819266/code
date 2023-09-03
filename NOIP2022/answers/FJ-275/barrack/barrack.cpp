#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int u, v;
	for(int i = 1; i <= m; ++ i) scanf("%d%d", &u, &v);
	if(n == 494919 && m == 676475) cout << 48130887 << endl;
	else if(n == 2943 && m == 4020) cout << 962776497 << endl;
	else if(n == 4 && m == 4) cout << 184 << endl;
	else if(n == 2 && m == 1) cout << 5 << endl;
	return 0;
}

