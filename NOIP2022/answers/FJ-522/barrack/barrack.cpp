#include<bits/stdc++.h>
using namespace std;

namespace Std{
	#define Add(x, y) make_pair(x, y)
	int used[1005], per[1005], ans = 0, n, m;
//	vector<pair<int, int> > G[1005];
	struct Map{ int u, v, w; } Edge[1005];
	
	void init(){
		scanf("%d%d", &n, &m);
		for(int i = 1, x, y; i <= m; i ++){
			cin >> Edge[i].u >> Edge[i].v;
//			G[x].push_back(Add(y, 0));
//			G[y].push_back(Add(x, 0));
		}
	}
	
	int Get_p(){
		int k = 1;
		for(int i = 1; i <= n; i ++){
			per[k] = !used[i] ? i : 0;
			k += !per[k] ? 0 : 1;
		}
		return k;
	}
	
	int Calc(int len){
		int ans = 0;
		for(int i = 1; i <= m; i ++){
			if(used[Edge[i].u] && used[Edge[i].v]) ans += 5;
			else ans += 2;
		}
		return ans;
	}
	
	int Get_permutation(int ans){
		for(int i = 1; i <= n; i ++){
			if(used[i]) continue;
			used[i] = 1;
			Get_permutation(ans + Calc(Get_p()));
			used[i] = 0;
		}
		return ans;
	}
}
using namespace Std;


int main(){
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	init();
	cout << Get_permutation(0) << endl;
	return 0;
}
//52ccf
